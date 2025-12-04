#include "bsp.h"
#include "main.h"


void TS_IO_Init(void) {
	//MX_I2C3_Init();
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = TS_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(TS_INT_GPIO_Port, &GPIO_InitStruct);
	HAL_GPIO_WritePin(TS_INT_GPIO_Port, TS_INT_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, GPIO_PIN_RESET);

}

inline void TS_IO_SetReset(uint8_t value)
{
	HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, value != 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

inline void TS_IO_Write(uint8_t Addr, uint16_t Reg, uint8_t Value) {
	I2C_Mem_Write(&hi2c3, Addr, Reg, I2C_MEMADD_SIZE_16BIT, &Value, 1, 100);
}

inline uint8_t TS_IO_Read(uint8_t Addr, uint16_t Reg) {
	uint8_t byte;
	I2C_Mem_Read(&hi2c3, Addr, Reg, I2C_MEMADD_SIZE_16BIT, &byte, 1, 100);
	return byte;
}

inline int8_t TS_IO_Transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size) {
	HAL_StatusTypeDef status = I2C_Master_Transmit(&hi2c3, DevAddress, pData, Size, 1000);
	if (status == HAL_OK)
		return 0;
	return -1;
}

inline int8_t TS_IO_Receive(uint16_t DevAddress, uint8_t *pData, uint16_t Size) {
	HAL_StatusTypeDef status = I2C_Master_Receive(&hi2c3, DevAddress, pData, Size, 1000);
	if (status == HAL_OK)
		return 0;
	return -1;
}

inline void TS_IO_Delay(uint32_t Delay) {
	HAL_Delay(Delay);
}

void TS_IO_SetI2CAddress(uint8_t Addr)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, GPIO_PIN_SET);
	if (Addr == 0x28 || Addr == 0x29)
	{
		HAL_GPIO_WritePin(TS_INT_GPIO_Port, TS_INT_Pin, GPIO_PIN_SET);
	}
	TS_IO_Delay(5);
	HAL_GPIO_WritePin(TS_INT_GPIO_Port, TS_INT_Pin, GPIO_PIN_RESET);
	TS_IO_Delay(50);

	GPIO_InitStruct.Pin = TS_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(TS_INT_GPIO_Port, &GPIO_InitStruct);

}
