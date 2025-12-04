#ifndef BOARD_TS_H
#define BOARD_TS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../Components/gt911/gt911.h"
#include "../Components/ili21x/ili21x.h"

#define TS_MAX_NB_TOUCH 			GT911_MAX_NB_TOUCH
#define TS_MULTI_TOUCH_SUPPORTED 	0

typedef enum 
{
	TS_OK                = 0x00,
	TS_ERROR             = 0x01,
	TS_TIMEOUT           = 0x02,
	TS_DEVICE_NOT_FOUND  = 0x03
}TS_StatusTypeDef;

typedef enum
{
	TS_SWAP_NONE	= 0x01,
	TS_SWAP_X		= 0x02,
	TS_SWAP_Y		= 0x04,
	TS_SWAP_XY		= 0x08
} TS_TouchSwap;

typedef enum
{
	GEST_ID_NO_GESTURE = 0x00,
	GEST_ID_MOVE_UP    = 0x01,
	GEST_ID_MOVE_RIGHT = 0x02,
	GEST_ID_MOVE_DOWN  = 0x03,
	GEST_ID_MOVE_LEFT  = 0x04,
	GEST_ID_ZOOM_IN    = 0x05,
	GEST_ID_ZOOM_OUT   = 0x06,
	GEST_ID_NB_MAX     = 0x07
} TS_GestureIdTypeDef;

typedef enum
{
	TOUCH_EVENT_NO_EVT        = 0x00,
	TOUCH_EVENT_PRESS_DOWN    = 0x01,
	TOUCH_EVENT_LIFT_UP       = 0x02,
	TOUCH_EVENT_CONTACT       = 0x03,
	TOUCH_EVENT_NB_MAX        = 0x04
} TS_TouchEventTypeDef;

typedef struct
{
	uint8_t  touchDetected;
	uint16_t touchX[TS_MAX_NB_TOUCH];
	uint16_t touchY[TS_MAX_NB_TOUCH];

#if (TS_MULTI_TOUCH_SUPPORTED == 1)
	uint8_t  touchWeight[TS_MAX_NB_TOUCH];
	uint8_t  touchEventId[TS_MAX_NB_TOUCH];
	uint8_t  touchArea[TS_MAX_NB_TOUCH];
	uint32_t gestureId;
#endif  /* TS_MULTI_TOUCH_SUPPORTED == 1 */
} TS_StateTypeDef;

TS_StatusTypeDef BSP_TS_Init(uint16_t ts_SizeX, uint16_t ts_SizeY);
TS_StatusTypeDef BSP_TS_DeInit(void);
uint8_t BSP_TS_GetState(TS_StateTypeDef *TS_State);

#if (TS_MULTI_TOUCH_SUPPORTED == 1)
uint8_t BSP_TS_Get_GestureId(TS_StateTypeDef *TS_State);
#endif /* TS_MULTI_TOUCH_SUPPORTED == 1 */

TS_StatusTypeDef BSP_TS_ITConfig(void);
uint8_t BSP_TS_ITGetStatus(void);
void    BSP_TS_ITClear(void);
uint8_t BSP_TS_ResetTouchData(TS_StateTypeDef *TS_State);
void 	BSP_TS_InterruptHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_TS_H */
