#pragma once
#include "instruction.h"
#include <iostream>
using namespace std;

class instMem
{
public:
	instMem();
	instruction *getInst(int);
	void allocate(instruction*);
	void print();
	~instMem();

private:
	vector<instruction*> Inst;
	int maxPc = -1;
};

instMem::instMem()
{
}

instruction* instMem::getInst(int p) {
	if(p<=maxPc)
		return Inst[p];
	else cout << "Invalid PC value! \n";

}
void instMem::allocate(instruction * newInst) {
	Inst.push_back(newInst);
	maxPc++;
}

void instMem::print() {
	for (instruction *x : Inst) {
		x->print();
	}
}
instMem::~instMem()
{
}