#include "Comm.hpp"
#include "string.h"

Comm::Comm(UART_HandleTypeDef& huart) : _huart(huart) {}

void Comm::Init()
{
	ReceiveByte();
}

void Comm::SendRequest(Command_t cmd)
{
	uint8_t command = (uint8_t) cmd;
	HAL_UART_Transmit_IT(&_huart, &command, sizeof(cmd));
}

void Comm::ReceiveByte()
{
    HAL_UART_Receive_IT(&_huart, rxBuffer, 4);
}

void Comm::ReceiveData()
{
    if(!usart2_rx_flag) return;
    memcpy(&receivedMass, rxBuffer, 4);
    receivedMassFloat = ((float)receivedMass) / 100.0f;
    receivedMassFloat = roundf(receivedMassFloat * 100.0f) / 100.0f;
    usart2_rx_flag = 0;
}

Comm comm1(huart2);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart2)
    {
    	comm1.usart2_rx_flag = 1;
    	comm1.ReceiveByte();
    }
}

