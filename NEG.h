#pragma once
#ifndef NEG_H
#define NEG_H

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
#endif

