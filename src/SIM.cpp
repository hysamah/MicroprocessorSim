#include "SIM.h"

SIM::SIM(const string & name) //contructor that initialises the instruction memory and Program Counter 
{
	this->program_name = name;
	this->file.open(program_name);
	this->run=1;
	while(!this->file.eof())
		this->file >> instMem;
	this->file.close();
	this->pc = 0;

	
}

void SIM::Run() //running the simulator 
{
	Instruction *Inst = nullptr;
	while (this->run) //keep the program running while the value run is true (ie; no HLT instruction called)
	{ 
		Inst = this->instMem.getInst(pc);  //get intruction to excute
		this->pc = Inst->excute(this->pc, this->dataMem, this->run);  //execute instruction and update pc
		cout << "Done excuting instruction" << endl<< endl; 
	}
}

void SIM::printInstructions() //Print then whole Instruction Memory 
{
	this->instMem.print();

}

void SIM::printData() //Print then whole Data Memory 
{
	this->dataMem.print();

}
SIM::~SIM(){
}