#include "../ili21x/ili21x.h"
#include "ilitek_protocol.h"

/* Touch screen driver structure initialization */
TS_DrvTypeDef ili21x_ts_drv = {
	ili21x_Init,
	ili21x_ReadID,
	ili21x_TS_Start,
	ili21x_TS_DetectTouch,
	ili21x_TS_GetXY,
	ili21x_TS_EnableIT,
	ili21x_TS_ClearIT,
	ili21x_TS_ITStatus,
	ili21x_TS_DisableIT,
	ili21x_TS_InterruptHandler
};

static uint8_t InterruptStatus = 0;
/************ PUBLIC FUNCTIONS DEFINITION ************/

/**
 * @brief  Initializes the tc i2c communication bus from MCU to ili21x
 * @retval None
 */
void ili21x_Init()
{
    ilitek_interface_init( );
    ilitek_reset( 1000 );

    unsigned char inbuf[16] = { 0 };
    unsigned char outbuf[16] = { 0 };
    api_protocol_init_func( );
    api_protocol_get_v6_tp_resolution(inbuf, outbuf);
    api_protocol_set_apmode(inbuf, outbuf);
}

/**
 * @brief  Read the gt222 device ID, pre initialize I2C in case of need to be
 *         able to read the ili21x device ID, and verify this is a ili21x.
 * @retval The Device ID (two bytes).
 */
uint8_t ili21x_ReadID()
{

	return true;
}

/**
 * @brief  Configures the touch Screen IC device to start detecting touches
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address).
 * @retval None.
 */
void ili21x_TS_Start()
{

}

/**
 * @brief  Return if there is touches detected or not.
 *         Try to detect new touches and forget the old ones (reset internal global
 *         variables).
 * @param  DeviceAddr: Device address on communication Bus.
 * @retval : Number of active touches detected (can be 0, 1 or 2).
 */
static uint16_t x, y;
uint8_t ili21x_TS_DetectTouch()
{
	if (ilitek_data->process_and_report() == 0)
	{
		for (int i = 0; i < ilitek_data->max_tp; ++i)
		{
			if (ilitek_data->touch_flag[i] == 1)
			{
				if (ilitek_data->tp[i].status == 1)
				{
					x = ilitek_data->tp[i].x;
					y = ilitek_data->tp[i].y;
					return 1;
				}
			}
		}
	}
	return 0;
}

/**
  * @brief  Get the touch screen X and Y positions values
  *         Manage multi touch thanks to touch Index global
  *         variable 'gt222_handle.currActiveTouchIdx'.
  * @param  X: Pointer to X position value
  * @param  Y: Pointer to Y position value
  * @retval None.
  */
void ili21x_TS_GetXY(uint16_t *X, uint16_t *Y) {
	*X = x;
	*Y = y;
}

/**
 * @brief  Configure the ili21x device to generate IT on given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void ili21x_TS_EnableIT() {
}

/**
 * @brief  Configure the ili21x device to stop generating IT on the given INT pin
 *         connected to MCU as EXTI.
 * @retval None
 */
void ili21x_TS_DisableIT() {
	//
}

/**
 * @brief  Get IT status from ili21x interrupt status registers
 *         Should be called Following an EXTI coming to the MCU to know the detailed
 *         reason of the interrupt.
 * @retval TS interrupts status
 */
uint8_t ili21x_TS_ITStatus() {
  return InterruptStatus;
}

/**
 * @brief  Clear IT status in ili21x interrupt status clear registers
 *         Should be called Following an EXTI coming to the MCU.
 * @retval TS interrupts status
 */
void ili21x_TS_ClearIT() {
	InterruptStatus = 0;
}

void ili21x_TS_InterruptHandler()
{
	InterruptStatus = 1;
}
