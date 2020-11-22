#pragma once
#ifndef INSTMEM_H
#define INSTMEM_H

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


enum names  //enumurating intruction names to instantiate correct instructions and add them to the Instruction memory
{
	adD = 68, neG = 71, asI = 73, jp0 = 48, jpA = 65, loE = 69, muL = 76, hlT = 84
};
class InstMem  //class for the instruction memory 
{
public:
	InstMem(); //class constructor 
	Instruction *getInst(int, int );  //getter for the instruction from the memory
	void allocate(Instruction&); //function to allocate new instructions into the memory 
	friend ifstream & operator >> (ifstream &, InstMem&);  //operator to read instructions from a file directly into the InstMem
	void print(); //print function for the instruction memory
	~InstMem();

private:
	Instruction** Inst;
	int maxPc = -1;
	int allocated; //numper of instructions in memory at any given time
};


#endif // !INSTMEM_H