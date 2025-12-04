#ifndef BSP_H
#define BSP_H

#include "i2c.h"

void 	TS_IO_Init(void);
void 	TS_IO_SetReset(uint8_t value);
void 	TS_IO_Write(uint8_t Addr, uint16_t Reg, uint8_t Value);
uint8_t	TS_IO_Read(uint8_t Addr, uint16_t Reg);
int8_t 	TS_IO_Transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
int8_t	TS_IO_Receive(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void 	TS_IO_Delay(uint32_t Delay);
void 	TS_IO_SetI2CAddress(uint8_t Addr);

#endif /* BSP_H */
