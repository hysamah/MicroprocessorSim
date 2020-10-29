#include <iostream>
#include <fstream>
#include <string>
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
	cout << "Printing All instructions in Instruction Memory \n";
	for (int i = 0; i < this->allocated; i++)
	{
		Inst[i]->print();
	}
	
	/*for (Instruction *x : Inst) {
		x->print();
	}*/
}




ifstream & operator >> (ifstream& file, InstMem& f)
{
	string data;
	string tmp;
	while (!file.eof()) {
		getline(file, tmp);
		data += tmp + '\n';
	}
	vector <vector<char *>> instructions;
	vector <char *> k;
	char **C, **F;
	C = new char *;
	F = new char*;
	char* tok;
	char *m;
	tok = strtok_s(&data[0], "\n", C);
	while (tok != NULL) {
		m = strtok_s(tok, " ", F);
		while (m != NULL) {
			k.push_back(m);
			m = strtok_s(NULL, " ", F);
		}
		instructions.push_back(k);
		k.clear();
		tok = strtok_s(NULL, "\n", C);
	}

	vector<Operand> OP;
	enum names
	{
		adD = 68, neG = 71, asI = 73, jp0 = 48, jpA = 65, loE = 69, muL = 76, hlT = 84
	};

	for (vector<char *> s : instructions)
	{
		OP.clear();
		for (int i = 1; i < s.capacity(); i++) {
			if (string(s[i - 1]) == "ASI") {
				Operand O(1, atoi(s[i]));
				OP.push_back(O);
			}
			else {
				Operand O(0, atoi(s[i]));
				OP.push_back(O);
			}
		}


		Instruction *InstPtr=nullptr;

		switch (int(string(s[0]).back()))
		{
		case adD:
		{
			InstPtr = new ADD(OP);
			break;
		}
		case neG: {
			InstPtr = new NEG(OP);
			break;
		}
			
		case muL: {
			InstPtr = new MUL(OP);
			break;
		}
		case hlT: {
			InstPtr = new HLT (OP);
			break;
		}
		case jp0: {
			InstPtr = new JP0 (OP);
			break;
		}
		case jpA: {
			InstPtr = new JPA (OP);
			break;
		}
		case asI: {
			InstPtr = new ASI (OP);
			break;
		}
		case loE: {
			InstPtr = new LOE (OP);
			break;
		}

		default:
			cout << "invalid instruction" << endl;
			break;
		}
		f.allocate(*InstPtr);

	}

	return file;
	
}

InstMem::~InstMem() {
	for (int i = 0; i < this->allocated; i++) {
		delete this->Inst[i];
	}
	delete[] this->Inst;
}

