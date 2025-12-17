#include "Comm.hpp"
#include "string.h"


Comm::Comm(UART_HandleTypeDef& huart) : _huart(huart) {}

typedef enum
{
	ASK_FOR_MASS = 0x02,

} Command_t;

void Comm::Init()
{
	ReceiveByte();
}

void Comm::SendRequest()
{
	uint8_t cmd = (uint8_t)ASK_FOR_MASS;
	HAL_UART_Transmit_IT(&_huart, &cmd, sizeof(cmd));
}

void Comm::ReceiveByte()
{
    HAL_UART_Receive_IT(&_huart, (uint8_t*)&rxByte, 1);
}

void Comm::ReceiveData()
{
    if(!usart2_rx_flag) return;

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

