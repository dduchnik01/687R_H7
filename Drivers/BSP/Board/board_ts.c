#include "board_ts.h"
#include <stddef.h>
#include "main.h"

static TS_DrvTypeDef *tsDriver;
static uint8_t tsOrientation;
static uint16_t tsXBoundary, tsYBoundary;

/**
  * @brief  Initializes and configures the touch screen functionalities and 
  *         configures all necessary hardware resources (GPIOs, I2C, clocks..).
  * @param  ts_SizeX: Maximum X size of the TS area on LCD
  * @param  ts_SizeY: Maximum Y size of the TS area on LCD
  * @retval TS_OK if all initializations are OK. Other value if error.
  */
TS_StatusTypeDef BSP_TS_Init(uint16_t ts_SizeX, uint16_t ts_SizeY)
{
	TS_StatusTypeDef status = TS_OK;
	tsXBoundary = ts_SizeX;
	tsYBoundary = ts_SizeY;
	tsOrientation = TS_SWAP_NONE;//TS_SWAP_XY | TS_SWAP_Y;
	
    tsDriver = &gt911_ts_drv;
	tsDriver->Init();

	if (tsDriver->ReadID())
	{//gt911 detected
		tsDriver->Start();
	}
	else
	{
	    tsDriver = &ili21x_ts_drv;
		tsDriver->Init();

		if(!tsDriver->ReadID()) {
			status = TS_DEVICE_NOT_FOUND;
			tsDriver = NULL;
			BSP_TS_DeInit();
		}else {
			tsDriver->Start();
		}
	}
	return status;
}

/**
  * @brief  DeInitializes the TouchScreen.
  * @retval TS state
  */
TS_StatusTypeDef BSP_TS_DeInit(void)
{ 
	tsXBoundary = 0;
	tsYBoundary = 0;
	tsOrientation = TS_SWAP_NONE;
	return TS_OK;
}

/**
  * @brief  Configures and enables the touch screen interrupts.
  * @retval TS_OK if all initializations are OK. Other value if error.
  */
TS_StatusTypeDef BSP_TS_ITConfig(void)
{
	GPIO_InitTypeDef gpio_init_structure = { 0 };

	// Configure Interrupt mode for SD detection pin
	gpio_init_structure.Pin = TS_INT_Pin;
	gpio_init_structure.Mode = GPIO_MODE_IT_FALLING;
	gpio_init_structure.Pull = GPIO_NOPULL;
 	HAL_GPIO_Init(TS_INT_GPIO_Port, &gpio_init_structure);

	return TS_OK;  
}

/**
  * @brief  Gets the touch screen interrupt status.
  * @retval TS_OK if all initializations are OK. Other value if error.
  */
uint8_t BSP_TS_ITGetStatus(void)
{
  // Return the TS IT status
  if (tsDriver)
  {
	  return tsDriver->GetITStatus();
  }
  return 0;
}

/**
  * @brief  Returns status and positions of the touch screen.
  * @param  TS_State: Pointer to touch screen current state structure
  * @retval TS_OK if all initializations are OK. Other value if error.
  */
uint8_t BSP_TS_GetState(TS_StateTypeDef *TS_State)
{
  static uint32_t _x[TS_MAX_NB_TOUCH] = {0};
  static uint32_t _y[TS_MAX_NB_TOUCH] = {0};
  uint8_t ts_status = TS_OK;
  uint16_t x[TS_MAX_NB_TOUCH];
  uint16_t y[TS_MAX_NB_TOUCH];
  uint16_t x_diff;
  uint16_t y_diff;
  uint32_t index;
#if (TS_MULTI_TOUCH_SUPPORTED == 1)
  uint32_t weight = 0;
  uint32_t area = 0;
  uint32_t event = 0;
#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */

  /* Check and update the number of touches active detected */
  TS_State->touchDetected = 0;
  if(tsDriver) {
	  TS_State->touchDetected = tsDriver->DetectTouch();
  }
  
  if(TS_State->touchDetected)
  {
    for(index=0; index < TS_State->touchDetected; index++)
    {
      /* Get each touch coordinates */
      tsDriver->GetXY((uint16_t*)&(_x[index]), (uint16_t*)&(_y[index]));

      if(tsOrientation == TS_SWAP_NONE)
      {
        _x[index] = _x[index];
        _y[index] = _y[index];
      }

      if(tsOrientation & TS_SWAP_XY) {
        _y[index] = _x[index];
        _x[index] = _y[index];
      }

      if(tsOrientation & TS_SWAP_X) {
        _x[index] = tsXBoundary - x[index];
      }

      if(tsOrientation & TS_SWAP_Y) {
        _y[index] = tsYBoundary - y[index];
      }

      x_diff = x[index] > _x[index]? (x[index] - _x[index]): (_x[index] - x[index]);
      y_diff = y[index] > _y[index]? (y[index] - _y[index]): (_y[index] - y[index]);

      x[index] = _x[index];
      y[index] = _y[index];

      if ((x_diff + y_diff) > 5)
      {
        TS_State->touchX[index] = x[index];
        TS_State->touchY[index] = y[index];
      }

#if (TS_MULTI_TOUCH_SUPPORTED == 1)

      /* Get touch info related to the current touch */
      ft5426_TS_GetTouchInfo(index, &weight, &area, &event);

      /* Update TS_State structure */
      TS_State->touchWeight[index] = weight;
      TS_State->touchArea[index]   = area;

      /* Remap touch event */
      switch(event)
      {
        case FT5426_TOUCH_EVT_FLAG_PRESS_DOWN	:
          TS_State->touchEventId[index] = TOUCH_EVENT_PRESS_DOWN;
          break;
        case FT5426_TOUCH_EVT_FLAG_LIFT_UP :
          TS_State->touchEventId[index] = TOUCH_EVENT_LIFT_UP;
          break;
        case FT5426_TOUCH_EVT_FLAG_CONTACT :
          TS_State->touchEventId[index] = TOUCH_EVENT_CONTACT;
          break;
        case FT5426_TOUCH_EVT_FLAG_NO_EVENT :
          TS_State->touchEventId[index] = TOUCH_EVENT_NO_EVT;
          break;
        default :
          ts_status = TS_ERROR;
          break;
      } /* of switch(event) */

#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */

    } /* of for(index=0; index < TS_State->touchDetected; index++) */

#if (TS_MULTI_TOUCH_SUPPORTED == 1)
    /* Get gesture Id */
    ts_status = BSP_TS_Get_GestureId(TS_State);
#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */

  } /* end of if(TS_State->touchDetected != 0) */

  return (ts_status);
}

/**
  * @brief  Clears all touch screen interrupts.
  */
void BSP_TS_ITClear(void)
{
  /* Clear TS IT pending bits */
  tsDriver->ClearIT(); 
}

/**
  * @brief  Function used to reset all touch data before a new acquisition
  *         of touch information.
  * @param  TS_State: Pointer to touch screen current state structure
  * @retval TS_OK if OK, TE_ERROR if problem found.
  */
uint8_t BSP_TS_ResetTouchData(TS_StateTypeDef *TS_State)
{
  uint8_t ts_status = TS_ERROR;
  uint32_t index;

  if (TS_State != (TS_StateTypeDef *)NULL)
  {
#if (TS_MULTI_TOUCH_SUPPORTED == 1)
    TS_State->gestureId = GEST_ID_NO_GESTURE;
    TS_State->touchDetected = 0;
#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */

    for(index = 0; index < TS_MAX_NB_TOUCH; index++)
    {
      TS_State->touchX[index]       = 0;
      TS_State->touchY[index]       = 0;
#if (TS_MULTI_TOUCH_SUPPORTED == 1)
      TS_State->touchArea[index]    = 0;
      TS_State->touchEventId[index] = TOUCH_EVENT_NO_EVT;
      TS_State->touchWeight[index]  = 0;
#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */
    }

    ts_status = TS_OK;

  } /* of if (TS_State != (TS_StateTypeDef *)NULL) */

  return (ts_status);
}

void BSP_TS_InterruptHandler()
{
	if (tsDriver)
		tsDriver->InterruptHandler();
}
