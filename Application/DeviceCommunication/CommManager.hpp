#ifndef DEVICECOMMUNICATION_COMMMANAGER_HPP_
#define DEVICECOMMUNICATION_COMMMANAGER_HPP_

#include "Commands.hpp"

class CommManager
{
public:
	float SendRequest(Command command);
private:

};

extern CommManager commManager;

#endif /* DEVICECOMMUNICATION_COMMMANAGER_HPP_ */
