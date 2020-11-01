#pragma once
#ifndef INSTRUCTION_H
#define INSTRUCTION_H



#include <vector>
#include "Operand.h"
#include "DataMem.h"

using namespace std;

class Instruction  //base class for all instructions 
{
public:
	Instruction(vector<Operand>); //constructor for intruction
	virtual void print()=0; //virtual function for printing the instruction 
	virtual int excute(int, DataMem&, bool& )=0; //virtual function for excuting the instruction 
	~Instruction ();
	
protected:
	vector <Operand> op;

};
#endif // !INSTRUCTION_H