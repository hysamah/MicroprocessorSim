#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class MUL : protected Instruction
{
public:
	MUL(vector <Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~MUL();

private:

};

