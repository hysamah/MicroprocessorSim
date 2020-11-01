  
#include "Operand.h"

Operand::Operand(bool t, int v): type(t), value(v) //operand constructor 
{

}

int Operand::getType() const {
	return type;
}

int Operand::getValue() const {
	return value;
}

Operand::~Operand()
{
}