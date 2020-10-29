#include <iostream>
#include "InstMem.h"
using namespace std;

InstMem::InstMem()
{
	this->Inst = new Instruction*[1024];
	this->allocated = 0;
}

Instruction* InstMem::getInst(int p) {
	if (p <= maxPc)
		return Inst[p];
	else cout << "Invalid PC value! \n";

}
void InstMem::allocate(Instruction& newInst) {
	if (this->allocated == 1024)
		throw overflow_error("Unable to allocate new space for a new instruction, size reached 1024");
	//cout << "SIZ: " << inst.pars.size() << endl;
	this->Inst[this->allocated] = &newInst;
	this->allocated++;
}

void InstMem::print() {
	for (int i = 0; i < this->allocated; i++)
	{
		Inst[i]->print();
	}
	
	/*for (Instruction *x : Inst) {
		x->print();
	}*/
}
InstMem::~InstMem() {
	for (int i = 0; i < this->allocated; i++) {
		delete this->Inst[i];
	}
	delete[] this->Inst;
}