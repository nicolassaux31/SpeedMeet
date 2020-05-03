#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

int num_of_slots = 1;
Model::slot slots[20];

Model::Model() : modelListener(0)
{
	slots[0].minutes = 0;
	slots[0].seconds = 0;
	slots[0].name = "UNDEF";

	slots[1].minutes = 0;
	slots[1].seconds = 0;
	slots[1].name = "UNDEF";

	slots[2].minutes = 0;
    slots[2].seconds = 0;
	slots[2].name = "UNDEF";

	slots[3].minutes = 0;
	slots[3].seconds = 0;
	slots[3].name = "UNDEF";
}

void Model::tick()
{

}
