#include "SIM.h"

SIM::SIM(const vector<string>& programs) //contructor that initialises the instruction memory and Program Counter 
{
	this->programs_num = programs.size();
	this->instMem = new InstMem[programs.size()];
	this->run = new bool[programs.size()];
	this->pc = new int[programs.size()];
	this->threads = new thread[programs.size()];
	for (int i = 0; i < programs.size(); i++) {
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
		this->pc[i] = Inst->excute(this->pc[i], this->dataMem, this->run[i]);  //execute instruction and update pc
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
		this->instMem[i].print();
	}

}

void SIM::printData() //Print then whole Data Memory 
{
	this->dataMem.print();

}
SIM::~SIM(){
}