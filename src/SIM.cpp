#include "SIM.h"

SIM::SIM(const vector<string>& programs) //contructor that initialises the instruction memory and Program Counter 
{
	this->programs_num = programs.size();
	this->instMem = new InstMem[this->programs_num];
	this->run = new bool[this->programs_num];
	this->pc = new int[this->programs_num];
	this->threads = new thread[this->programs_num];
	this->programs = programs;
	for (int i = 0; i < this->programs_num; i++) {
		string program_name = programs[i];
		this->file.open(program_name);
		this->run[i] = 1;
		this->pc[i] = 0;
		while (!this->file.eof())
			this->file >> instMem[i];
		this->file.close();
	}
}

void SIM::RunProgram(int i) //running the simulator 
{
	Instruction *Inst = nullptr;
	while (this->run[i]) //keep the program running while the value run is true (ie; no HLT instruction called)
	{ 
		Inst = this->instMem[i].getInst(pc[i]);  //get intruction to excute
		cout << "Thread #" << i << endl;
		Inst->lockOperands(this->dataMem);
		this->pc[i] = Inst->excute(this->pc[i], this->dataMem, this->run[i]);  //execute instruction and update pc
		Inst->unlockOperands(this->dataMem);
		cout << "Done excuting instruction" << endl<< endl; 
	}
}

void SIM::Run() {
	for (int i = 0; i < this->programs_num; i++) {
		this->threads[i] = thread(&SIM::RunProgram, this, i);
	}
	for (int i = 0; i < this->programs_num; i++) {
		this->threads[i].join();
	}
}

void SIM::printInstructions() //Print then whole Instruction Memory 
{
	for (int i = 0; i < this->programs_num; i++) {
		cout << "Instruction memory for " << this->programs[i] 
			<< " executed on thread #" << i << endl;
		this->instMem[i].print();

		cout << endl << endl;
	}

}

void SIM::printData() //Print then whole Data Memory 
{
	this->dataMem.print();

}
SIM::~SIM(){
}