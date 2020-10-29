#pragma once
#include "Instruction.h"
#include <iostream>
using namespace std;

class InstMem
{
public:
	InstMem();
	Instruction *getInst(int);
	void allocate(Instruction&);
	void print();
	~InstMem();

private:
	Instruction** Inst;
	int maxPc = -1;
	int allocated;
};


