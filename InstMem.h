#pragma once
#include "Instruction.h"
#include"ADD.h"
#include "ASI.h"
#include "HLT.h"
#include "JP0.h"
#include "JPA.h"
#include "LOE.h"
#include "MUL.h"
#include "NEG.h"
#include <fstream>
#include <iostream>
using namespace std;

#ifndef INSTMEM_H
#define INSTMEM_H


enum names
{
	adD = 68, neG = 71, asI = 73, jp0 = 48, jpA = 65, loE = 69, muL = 76, hlT = 84
};
class InstMem
{
public:
	InstMem();
	Instruction *getInst(int);
	void allocate(Instruction&);
	friend ifstream & operator >> (ifstream &, InstMem&);
	void print();
	~InstMem();

private:
	Instruction** Inst;
	int maxPc = -1;
	int allocated;
};


#endif // !INSTMEM_H