#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class NEG : public Instruction
{
public:
	NEG(vector<Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~NEG();

private:

};

