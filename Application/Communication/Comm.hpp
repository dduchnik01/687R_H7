#ifndef COMMUNICATION_COMM_HPP_
#define COMMUNICATION_COMM_HPP_

#include "../../Core/Inc/usart.h"
#include "ringBuffer.h"

#define RX_BUFFER_SIZE	15

typedef enum
{
	ASK_FOR_MASS = 0x02,

} Command_t;

class Comm
{
public:
	Comm(UART_HandleTypeDef& huart);
	void Init();
    void ReceiveByte();
	void ReceiveData();
	void SendRequest(Command_t cmd);
	volatile uint8_t usart2_rx_flag = 0;
    volatile uint8_t rxByte;
    uint8_t rxBuffer[4];
    uint32_t receivedMass;
    float receivedMassFloat;

private:
    UART_HandleTypeDef& _huart;
    uint8_t rxBufferIndex = 0;

};

extern Comm comm1;

#endif /* COMMUNICATION_COMM_HPP_ */
