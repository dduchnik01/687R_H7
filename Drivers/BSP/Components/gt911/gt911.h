/**
 ******************************************************************************
 * @file    gt911.h
 * @author  Joao Costa - costasjf@gmail.com
 * @brief   This file contains all the functions prototypes for the
 *          gt911.c Touch screen driver.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GT911_H
#define __GT911_H

#ifdef __cplusplus
extern "C" {
#endif

/************ INCLUDES ************/

#include "../../Board/ts.h"


/************ DEFINITIONS ************/

/* GT911 registers used in this driver: */
//#define GT911_I2C_ADDRESS	((uint8_t)0x28)
#define GT911_I2C_ADDRESS	((uint8_t)0xBA)

#define GT911_ESD_CHECK		((uint16_t)0x8041)	//ESD protection check, reset to 0 upon initialization
#define GT911_WIDTH_LSB		((uint16_t)0x8048)	//Resolution of X axis ( low byte )
#define GT911_WIDTH_MSB		((uint16_t)0x8049)	//Resolution of X axis ( high byte )
#define GT911_HEIGHT_LSB	((uint16_t)0x804A)	//Resolution of Y axis ( low byte )
#define GT911_HEIGHT_MSB	((uint16_t)0x804B)	//Resolution of Y axis ( high byte )
#define GT911_TP_MAX_SET	((uint16_t)0x804C)	//4 lsb -> touch points supported: 1 to 5
#define GT911_MODULE_SWITCH ((uint16_t)0x804D)	//TP Config
#define GT911_CONF_CHECK	((uint16_t)0x80FF)	//Configuration verification (checksum value 0x8047 to 0x80FE)
#define GT911_CONF_REFRESH	((uint16_t)0x8100)	//Configuration update flag (written by host)
#define GT911_CHIP_ID_REG1	((uint16_t)0x8140)	//Product ID ( first byte，ASCII )
#define GT911_CHIP_ID_REG2	((uint16_t)0x8141)	//Product ID ( second byte，ASCII )
#define GT911_CHIP_ID_REG3	((uint16_t)0x8142)	//Product ID ( third byte，ASCII )
#define GT911_CHIP_ID_REG4	((uint16_t)0x8143)	//Product ID ( forth byte，ASCII )
#define GT911_FIRM_VER_LSB	((uint16_t)0x8144)	//Firmware version ( HEX. low byte )
#define GT911_FIRM_VER_MSB	((uint16_t)0x8145)	//Firmware version ( HEX. high byte )
#define GT911_COORD_X_LSB	((uint16_t)0x8146)	//x coordinate resolution ( low byte )
#define GT911_COORD_X_MSB	((uint16_t)0x8147)	//x coordinate resolution ( high byte )
#define GT911_COORD_Y_LSB	((uint16_t)0x8148)	//y coordinate resolution ( low byte )
#define GT911_COORD_Y_MSB	((uint16_t)0x8149)	//y coordinate resolution ( high byte )
#define GT911_CHIP_ID_REG	((uint16_t)0x814A)	//Vendor_id ( ID of the current module )
#define GT911_TP_STAT_REG	((uint16_t)0x814E)	//Touch Data Status register (4lsb = number of touch points)
#define GT911_POINT_X_LOW	((uint16_t)0x8150)	//Point 1 x coordinate (low byte)
#define GT911_POINT_X_HIGH	((uint16_t)0x8151)	//Point 1 x coordinate (high byte)
#define GT911_POINT_Y_LOW	((uint16_t)0x8152)	//Point 1 y coordinate (low byte)
#define GT911_POINT_Y_HIGH	((uint16_t)0x8153)	//Point 1 y coordinate (high byte)

/* GT911 definitions used in this driver: */
#define GT911_MAX_NB_TOUCH			((uint8_t)0x01)
#define GT911_STATUS_OK				((uint8_t)0x00)		//:-)
#define GT911_STATUS_NOT_OK			((uint8_t)0x01)		//There's something wrong! :-(
#define GT911_I2C_NOT_INITIALIZED	((uint8_t)0x00)		//I2C not initiated
#define GT911_I2C_INITIALIZED		((uint8_t)0x01)		//I2C already initiated
#define GT911_4LSB_MASK				((uint8_t)0x0F)		//Mask for four last bit use only
#define GT911_TP_MAX_WIDTH			((uint16_t)800)		//Touchscreen pad max width
#define GT911_TP_MAX_HEIGHT			((uint16_t)480)		//Touchscreen pad max height
#define GT911_TOUCH_POS_MSB_MASK	((uint8_t)0x0F)
#define GT911_TOUCH_POS_LSB_MASK	((uint8_t)0xFF)
#define GT911_TOUCH_POS_MSB_SHIFT	((uint8_t)0x00)
#define GT911_TOUCH_POS_LSB_SHIFT	((uint8_t)0x00)
#define GT911_VENDOR_ID_VALUE		((uint8_t)0x03)

#define GT911_INT_LEVEL_MASK		((uint8_t)0x03)
#define GT911_INT_LOW_LEVEL_CONFIG	((uint8_t)0x02)
#define GT911_INT_HIGH_LEVEL_CONFIG	((uint8_t)0x03)

typedef struct //GT911 Handle definition type definition
{
	uint8_t i2cInitialized;		//I2C already initialized?
	uint8_t currActiveTouchNb;	//Current number of simultaneous active touches
} gt911_handle_TypeDef;


/************ PUBLIC FUNCTIONS PROTOTYPES ************/

/**
 * @brief  Initialize the gt911 communication bus
 *         from MCU to GT911 : ie I2C channel initialization (if required).
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address of GT911).
 * @retval None
 */
void gt911_Init();

/**
 * @brief  Software Reset the gt911.
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address of GT911).
 * @retval None
 */
void gt911_Reset();

/**
 * @brief  Read the gt911 device ID, pre initialize I2C in case of need to be
 *         able to read the GT911 device ID, and verify this is a GT911.
 * @param  DeviceAddr: I2C GT911 Slave address.
 * @retval The Device ID (two bytes).
 */
uint8_t gt911_ReadID();

/**
 * @brief  Configures the touch Screen IC device to start detecting touches
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address).
 * @retval None.
 */
void gt911_TS_Start();

/**
 * @brief  Return if there is touches detected or not.
 *         Try to detect new touches and forget the old ones (reset internal global
 *         variables).
 * @param  DeviceAddr: Device address on communication Bus.
 * @retval : Number of active touches detected (can be 0, 1 or 2).
 */
uint8_t gt911_TS_DetectTouch();

/**
  * @brief  Get the touch screen X and Y positions values
  *         Manage multi touch thanks to touch Index global
  *         variable 'gt911_handle.currActiveTouchIdx'.
  * @param  X: Pointer to X position value
  * @param  Y: Pointer to Y position value
  * @retval None.
  */
void gt911_TS_GetXY(uint16_t *X, uint16_t *Y);

/**
 * @brief  Configure the GT911 device to generate IT on given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void gt911_TS_EnableIT();

/**
 * @brief  Configure the GT911 device to stop generating IT on the given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void gt911_TS_DisableIT();

/**
 * @brief  Get IT status from GT911 interrupt status registers
 *         Should be called Following an EXTI coming to the MCU to know the detailed
 *         reason of the interrupt.
 * @retval TS interrupts status
 */
uint8_t gt911_TS_ITStatus();

/**
 * @brief  Clear IT status in GT911 interrupt status clear registers
 *         Should be called Following an EXTI coming to the MCU.
 * @retval TS interrupts status
 */
void gt911_TS_ClearIT();

void gt911_TS_InterruptHandler();


/************ IMPORTED ************/

//Imported TouchScreen (TS) external IO functions:
extern void    	TS_IO_Init(void);
extern void    	TS_IO_Write(uint8_t Addr, uint16_t Reg, uint8_t Value);
extern uint8_t	TS_IO_Read(uint8_t Addr, uint16_t Reg);
extern void    	TS_IO_Delay(uint32_t Delay);
extern void     TS_IO_SetI2CAddress(uint8_t Addr);

//Imported global touch variables screen driver structure
extern TS_DrvTypeDef gt911_ts_drv;


#ifdef __cplusplus
}
#endif
#endif /* __GT911_H */
