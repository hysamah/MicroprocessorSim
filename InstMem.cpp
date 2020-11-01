#include <iostream>
#include <fstream>
#include <string>
#include "InstMem.h"
using namespace std;

InstMem::InstMem()
{
	this->Inst = new Instruction*[1024];  //allocating space for the instructions of size 1024
	this->allocated = 0; //the initial number of instructions=0
}

Instruction* InstMem::getInst(int p) //getter function to retrieve an innstruction from a certain PC
{
	if (p < this->allocated){
		cout << "Getting instruction #" << p<<endl;
		return Inst[p];
	}
	else throw runtime_error("Invalid PC value");  //if PC value is out of the allocated range, throw this exception

}
void InstMem::allocate(Instruction& newInst) //allocating instructions at the bottom of the intruction memory
{
	if (this->allocated == 1024)
		throw overflow_error("Unable to allocate new space for a new instruction, size reached 1024");
	this->Inst[this->allocated] = &newInst;
	this->allocated++;
}

void InstMem::print() //printing function that prints all intructions in the memory
{
	cout << "-----------------------------------------\n";
	cout << "** Instructions in Instruction Memory ** \nPC ==> Instruction\n";
	for (int i = 0; i < this->allocated; i++)
	{
		cout << i << " ==> ";
		Inst[i]->print();
	}
	cout << "-----------------------------------------\n";
	
}


ifstream & operator >> (ifstream& file, InstMem& instMem)  //function to read, parse, and allocate instructions
{
	string data;
	getline(file, data);


	int l = 0, r;
    vector<string> list;
    while(l < data.length() && data[l] == ' ' || data[l] == '\t')l++;
    r = l;
    while(l < data.length()){
        while(r < data.length() && data[r] != ' ' && data[r] != '\t' && data[r] != ',') r++;
        list.push_back(data.substr(l, r - l));
        while(r < data.length() && data[r] == ' ' || data[r] == '\t' || data[r] == ',') r++;
        l = r;
        if(list.size() > 4)
            throw invalid_argument("Too many parameters in one line. Around: " + data);
    }
	


	vector<Operand> OP;


	for (int i = 1; i < list.size(); i++) {
		if (list[i - 1] == "ASI") {
			Operand O(1, atoi(list[i].c_str()));
			OP.push_back(O);
		}
		else {
			Operand O(0, atoi(list[i].c_str()));
			OP.push_back(O);
		}
	}


		Instruction *InstPtr=nullptr;

		switch (int(string(list[0]).back())) //switch statement to determine the type of intruction and allocating it to instruction memory
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
		instMem.allocate(*InstPtr);

	

	return file;
	
}

InstMem::~InstMem() {
	cout << "Deleting the instruction memory" <<endl;
	for (int i = 0; i < this->allocated; i++) {
		delete this->Inst[i];
	}
	delete[] this->Inst;
}

