#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <iostream>
using namespace std;

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    //Global HMI Objects
    class slot
    {
    public:
    	int minutes = 0;
    	int seconds = 0;
    	string name = "UNDEF";
    };

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
