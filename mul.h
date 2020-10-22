#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class MUL : protected Instruction
{
public:
	MUL(vector <Operand>);
	int excute(int, DataMem &);
	void print();
	~MUL();

private:

};

