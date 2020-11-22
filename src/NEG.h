#ifndef NEG_H
#define NEG_H

#include "Instruction.h"
#include <iostream>
using namespace std;

//derived functionn from instruction class for NEG
class NEG : public Instruction
{
public:
	NEG(vector<Operand>);
	int excute(int, DataMem &, bool& running);
	stringstream print();
	~NEG();

private:

};
#endif

