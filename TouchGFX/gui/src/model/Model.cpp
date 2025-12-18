#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "../../Application/Communication/Comm.hpp"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	modelListener->finalMassChanged(comm1.receivedMassFloat);
	modelListener->fBeforeChanged(10);
	modelListener->fAfterChanged(10);

}
