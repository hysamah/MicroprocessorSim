#pragma once
#ifndef INSTRUCTION_H
#define INSTRUCTION_H



#include <vector>
#include "Operand.h"
#include "DataMem.h"

using namespace std;

class Instruction 
{
public:
	Instruction(vector<Operand>);
	virtual void print()=0;
	virtual int excute(int, DataMem&, bool& )=0;
	~Instruction ();
	
protected:
	vector <Operand> op;

};
#endif // !INSTRUCTION_H