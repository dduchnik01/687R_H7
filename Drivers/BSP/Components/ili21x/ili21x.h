#ifndef BSP_COMPONENTS_ILI21X_ILI21X_H_
#define BSP_COMPONENTS_ILI21X_ILI21X_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../Board/ts.h"

#define ILITEK_I2C_ADDRESS					((uint8_t)(0x41<<1))

#define ILITEK_TP_CMD_GET_TP_RES			0x20
#define ILITEK_TP_CMD_GET_SCRN_RES			0x21
#define ILITEK_TP_CMD_SET_IC_SLEEP			0x30
#define ILITEK_TP_CMD_SET_IC_WAKE			0x31
#define ILITEK_TP_CMD_GET_FW_VER			0x40
#define ILITEK_TP_CMD_GET_PRL_VER			0x42
#define ILITEK_TP_CMD_GET_MCU_VER			0x61
#define ILITEK_TP_CMD_GET_IC_MODE			0xC0

#define REPORT_COUNT_ADDRESS				61
#define ILITEK_SUPPORT_MAX_POINT			40


void 	ili21x_Init();
uint8_t ili21x_ReadID();
void 	ili21x_TS_Start();
uint8_t ili21x_TS_DetectTouch();
void 	ili21x_TS_GetXY(uint16_t *X, uint16_t *Y);
void 	ili21x_TS_EnableIT();
void 	ili21x_TS_DisableIT();
uint8_t ili21x_TS_ITStatus();
void 	ili21x_TS_ClearIT();
void	ili21x_TS_InterruptHandler();

//Imported global touch variables screen driver structure
extern TS_DrvTypeDef ili21x_ts_drv;

#ifdef __cplusplus
}
#endif
#endif /* BSP_COMPONENTS_ILI21X_ILI21X_H_ */
