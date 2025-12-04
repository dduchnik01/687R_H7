#include "MainApplication.hpp"
#include "DeviceCommunication/CommManager.hpp"

void MainApplicationInit(void)
{

}

void MainApplicationLoop()
{
	//timer.Set(500); // 500ms
	commManager.SendRequest(Command::MASS_GRAMS);

}
