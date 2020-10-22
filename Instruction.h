#pragma once
#include <vector>
#include "Operand.h"
#include "DataMem.h"

using namespace std;

class Instruction 
{
public:
	Instruction(vector<Operand>);
	virtual void print()=0;
	virtual int excute(int, DataMem&)=0;
	~Instruction ();
	
protected:
	vector <Operand> op;

};
