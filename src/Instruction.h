#pragma once
#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <sstream>
#include <vector>
#include <set>
#include "Operand.h"
#include "DataMem.h"

using namespace std;

class Instruction  //base class for all instructions 
{
public:
	Instruction(vector<Operand>); //constructor for intruction
	virtual stringstream print()=0; //virtual function for printing the instruction 
	virtual int excute(int, DataMem&, bool&, int thrd=0 )=0; //virtual function for excuting the instruction 
	void lockOperands(DataMem&);
    void unlockOperands(DataMem&);
	~Instruction ();
	
protected:
	//stringstream stream;
	vector <Operand> op;
	set<int, greater<int>> locks;

};
#endif // !INSTRUCTION_H