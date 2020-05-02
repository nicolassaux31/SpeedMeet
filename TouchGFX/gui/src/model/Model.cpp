#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::slot slots[4];

Model::Model() : modelListener(0)
{
	slots[0].minutes = 10;
	slots[0].seconds = 25;
	slots[0].name = "UNDEF";

	slots[1].minutes = 10;
	slots[1].seconds = 25;
	slots[1].name = "UNDEF";

	slots[2].minutes = 10;
    slots[2].seconds = 25;
	slots[2].name = "UNDEF";

	slots[3].minutes = 10;
	slots[3].seconds = 25;
	slots[3].name = "UNDEF";
}

void Model::tick()
{

}
