#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class NEG : protected Instruction
{
public:
	NEG(vector<Operand>);
	int excute(int, DataMem &);
	void print();
	~NEG();

private:

};

