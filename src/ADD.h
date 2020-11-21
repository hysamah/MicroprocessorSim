#ifndef ADD_H
#define ADD_H


#include "Instruction.h"
#include <iostream>

using namespace std;

//derived functionn from instruction class for ADD
class ADD : public Instruction
{
public:
	ADD(vector <Operand>);
	int excute(int, DataMem&, bool& running);
	void print();
	~ADD();

private:

};

#endif // !ADD_H