#include "MainApplication.hpp"
#include "../Core/Inc/usart.h"
#include "Communication/Comm.hpp"
#include "string.h"

void MainApplicationInit(void)
{
	comm1.Init();
}

void MainApplicationLoop(void)
{
	comm1.SendRequest();
	comm1.ReceiveData();
}

