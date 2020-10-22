#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class ADD : protected Instruction
{
public:
	ADD(vector <Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~ADD();

private:

};

