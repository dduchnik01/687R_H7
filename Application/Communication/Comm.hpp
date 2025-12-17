#ifndef COMMUNICATION_COMM_HPP_
#define COMMUNICATION_COMM_HPP_

#include "../../Core/Inc/usart.h"
#include "ringBuffer.h"

#define RX_BUFFER_SIZE	15

class Comm
{
public:
	Comm(UART_HandleTypeDef& huart);
	void Init();
    void ReceiveByte();
	void ReceiveData();
	void SendRequest();
	volatile uint8_t usart2_rx_flag = 0;
    volatile uint8_t rxByte;
    RingBuffer_t ringBuffer;

private:
    UART_HandleTypeDef& _huart;
    uint8_t rxBufferIndex = 0;

};

extern Comm comm1;

#endif /* COMMUNICATION_COMM_HPP_ */
