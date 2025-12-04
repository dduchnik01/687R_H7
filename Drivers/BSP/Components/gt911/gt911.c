#include "gt911.h"
#include "main.h"

/* Touch screen driver structure initialization */
TS_DrvTypeDef gt911_ts_drv = {
	gt911_Init,
	gt911_ReadID,
	gt911_TS_Start,
	gt911_TS_DetectTouch,
	gt911_TS_GetXY,
	gt911_TS_EnableIT,
	gt911_TS_ClearIT,
	gt911_TS_ITStatus,
	gt911_TS_DisableIT,
	gt911_TS_InterruptHandler,
};


/************ PRIVATE VARIABLES ************/

static gt911_handle_TypeDef gt911_ts_handle; //GT911 touch handle variable


/************ PUBLIC VARIABLES ************/


/************ PRIVATE FUNCTIONS PROTOTYPES ************/

/**
 * @brief  Returns if I2C was previous initialized or not.
 * @param  None.
 * @retval : I2C initialization status.
 */
static uint8_t gt911_Get_I2C_InitializedStatus(void);

/**
 * @brief  I2C initialize if needed.
 * @param  None.
 * @retval : None.
 */
static void gt911_I2C_InitializeIfRequired(void);

/**
 * @brief  Basic static configuration of TouchScreen
 * @param  DeviceAddr: GT911 Device address for communication on I2C Bus.
 * @retval Status GT911_STATUS_OK or GT911_STATUS_NOT_OK.
 */
static uint32_t gt911_TS_Configure(uint8_t DeviceAddr);


/************ PUBLIC FUNCTIONS DEFINITION ************/

/**
 * @brief  Initializes the gt911 i2c communication bus from MCU to GT911
 * @retval None
 */
void gt911_Init()
{
	/* Initialize I2C link if needed */
	gt911_I2C_InitializeIfRequired();

	TS_IO_SetI2CAddress(GT911_I2C_ADDRESS);
	//gt911_ts_handle.i2cInitialized = GT911_I2C_NOT_INITIALIZED;
	gt911_ts_handle.currActiveTouchNb = 0;
}

/**
 * @brief  Read the gt911 device ID, pre initialize I2C in case of need to be
 *         able to read the GT911 device ID, and verify this is a GT911.
 * @retval The Device ID (two bytes).
 */
uint8_t gt911_ReadID()
{
	uint8_t attemptscount = 0;
	uint8_t devicefounded = 0;

	//Initialize I2C link if needed
	gt911_I2C_InitializeIfRequired();

	//Maximum of 4 attempts to read ID
	for(attemptscount = 0; ((attemptscount < 3) && !(devicefounded)); attemptscount++)
	{
		//Read gt911 ID registers: ASCII -> "9110"
		if((TS_IO_Read(GT911_I2C_ADDRESS, GT911_CHIP_ID_REG1) == 0x39) && \
				(TS_IO_Read(GT911_I2C_ADDRESS, GT911_CHIP_ID_REG2) == 0x32) &&\
				(TS_IO_Read(GT911_I2C_ADDRESS, GT911_CHIP_ID_REG3) == 0x38) &&\
				(TS_IO_Read(GT911_I2C_ADDRESS, GT911_CHIP_ID_REG4) == 0x00))
		{
			/* Set device as found */
			devicefounded = 1;
		}
	}
	/* Return the device ID value */
	return devicefounded;
}

/**
 * @brief  Configures the touch Screen IC device to start detecting touches
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address).
 * @retval None.
 */
void gt911_TS_Start()
{
	//uint8_t teste[2] = {0, 0};
	/* Minimum static configuration of GT911 */
	gt911_TS_Configure(GT911_I2C_ADDRESS);

	/* By default set GT911 IC in Polling mode : no INT generation on GT911 for new touch available */
	/* Note TS_INT is active low                                                                      */
	gt911_TS_EnableIT();

	uint16_t chksum = 0;
	uint8_t checksum = 0;
	//	uint8_t touch_number = 0;

	//Reads current checksum value:
	checksum = TS_IO_Read(GT911_I2C_ADDRESS, GT911_CONF_CHECK);

	//Writes the number of touch points config register:
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_TP_MAX_SET, GT911_MAX_NB_TOUCH);

	//Calculates new checksum:
	for(uint16_t reg = 0x8047; reg <= 0x80FE; ++reg)
		chksum += TS_IO_Read(GT911_I2C_ADDRESS, reg);

	chksum = ~chksum +1;
	checksum = (uint8_t)chksum;

	TS_IO_Write(GT911_I2C_ADDRESS, GT911_CONF_CHECK, checksum);
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_CONF_REFRESH, 0x01);
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_ESD_CHECK, 0x00);

	TS_IO_Delay(10);

	//Cleans the status register for the new touch read
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_TP_STAT_REG, 0);

	/* By default set GT911 IC in Polling mode : no INT generation on GT911 for new touch available */
	/* Note TS_INT is active low                                                                      */
	//gt911_TS_DisableIT(DeviceAddr);
}

/**
 * @brief  Return if there is touches detected or not.
 *         Try to detect new touches and forget the old ones (reset internal global
 *         variables).
 * @param  DeviceAddr: Device address on communication Bus.
 * @retval : Number of active touches detected (can be 0, 1 or 2).
 */
static uint16_t x, y;
uint8_t gt911_TS_DetectTouch()
{
	volatile uint8_t nbTouch = 0;
	volatile uint8_t touch_status = 0;
	volatile uint8_t ucReadData = 0;
	static uint16_t coord;

	//Read register GT911_TD_STAT_REG to check number of touches detection
	touch_status = TS_IO_Read(GT911_I2C_ADDRESS, GT911_TP_STAT_REG);
	//touch_status = TS_IO_Read(DeviceAddr, 0x81A8);
	nbTouch = touch_status & GT911_4LSB_MASK; //Just the 4 LSB refers to active touch points

	if(touch_status)
	{
		ucReadData = TS_IO_Read(GT911_I2C_ADDRESS, GT911_POINT_X_LOW);
		coord = (ucReadData & GT911_TOUCH_POS_LSB_MASK) >> GT911_TOUCH_POS_LSB_SHIFT;
		/* Read high part of X position */
		ucReadData = TS_IO_Read(GT911_I2C_ADDRESS, GT911_POINT_X_HIGH);
		coord |= ((ucReadData & GT911_TOUCH_POS_MSB_MASK) >> GT911_TOUCH_POS_MSB_SHIFT) << 8;
		/* Send back ready X position to caller */
		x = coord;

		/* Read low part of Y position */
		ucReadData = TS_IO_Read(GT911_I2C_ADDRESS, GT911_POINT_Y_LOW);
		coord = (ucReadData & GT911_TOUCH_POS_LSB_MASK) >> GT911_TOUCH_POS_LSB_SHIFT;
		/* Read high part of Y position */
		ucReadData = TS_IO_Read(GT911_I2C_ADDRESS, GT911_POINT_Y_HIGH);
		coord |= ((ucReadData & GT911_TOUCH_POS_MSB_MASK) >> GT911_TOUCH_POS_MSB_SHIFT) << 8;
		/* Send back ready Y position to caller */
		y = coord;

		//Cleans the status register for the new touch read
		TS_IO_Write(GT911_I2C_ADDRESS, GT911_TP_STAT_REG, 0);

		//Is data ready for reading and touch detected?
		if(nbTouch > 1)
		{
			nbTouch = 0;
		}
	}

	/* Update gt911 driver internal global : current number of active touches */
	gt911_ts_handle.currActiveTouchNb = nbTouch;

	return(nbTouch);
}

/**
  * @brief  Get the touch screen X and Y positions values
  *         Manage multi touch thanks to touch Index global
  *         variable 'gt911_handle.currActiveTouchIdx'.
  * @param  X: Pointer to X position value
  * @param  Y: Pointer to Y position value
  * @retval None.
  */
void gt911_TS_GetXY(uint16_t *X, uint16_t *Y) {
	*X = x;
	*Y = y;
}


/* Static functions bodies-----------------------------------------------*/


/**
 * @brief  Return the status of I2C was initialized or not.
 * @param  None.
 * @retval : I2C initialization status.
 */
static uint8_t gt911_Get_I2C_InitializedStatus(void)
{
	return(gt911_ts_handle.i2cInitialized);
}

/**
 * @brief  I2C initialize if needed.
 * @param  None.
 * @retval : None.
 */
static void gt911_I2C_InitializeIfRequired(void)
{
	if(gt911_Get_I2C_InitializedStatus() == GT911_I2C_NOT_INITIALIZED)
	{
		/* Initialize TS IO BUS layer (I2C) */
		TS_IO_Init();
		/* Set state to initialized */
		gt911_ts_handle.i2cInitialized = GT911_I2C_INITIALIZED;
	}
}

/**
 * @brief  Basic static configuration of TouchScreen
 * @param  DeviceAddr: GT911 Device address for communication on I2C Bus.
 * @retval Status GT911_STATUS_OK or GT911_STATUS_NOT_OK.
 */
static uint32_t gt911_TS_Configure(uint8_t DeviceAddr)
{
	uint32_t status = GT911_STATUS_OK;
	/* Nothing special to be done for GT911 */
	return(status);
}

/**
 * @brief  Configure the GT911 device to generate IT on given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void gt911_TS_EnableIT() {
	uint8_t value = TS_IO_Read(GT911_I2C_ADDRESS, GT911_MODULE_SWITCH);
	value &= ~GT911_INT_LEVEL_MASK;
	value |= GT911_INT_HIGH_LEVEL_CONFIG;
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_MODULE_SWITCH, value);
}

/**
 * @brief  Configure the GT911 device to stop generating IT on the given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void gt911_TS_DisableIT() {
	uint8_t value = TS_IO_Read(GT911_I2C_ADDRESS, GT911_MODULE_SWITCH);
	value &= ~GT911_INT_LEVEL_MASK;
	TS_IO_Write(GT911_I2C_ADDRESS, GT911_MODULE_SWITCH, value);
}

/**
 * @brief  Get IT status from GT911 interrupt status registers
 *         Should be called Following an EXTI coming to the MCU to know the detailed
 *         reason of the interrupt.
 * @retval TS interrupts status
 */
uint8_t gt911_TS_ITStatus() {
	return HAL_GPIO_ReadPin(TS_INT_GPIO_Port, TS_INT_Pin) == GPIO_PIN_SET;
}

/**
 * @brief  Clear IT status in GT911 interrupt status clear registers
 *         Should be called Following an EXTI coming to the MCU.
 * @retval TS interrupts status
 */
void gt911_TS_ClearIT() {
	/* Nothing to be done here for GT911 */
}

void gt911_TS_InterruptHandler()
{
}
