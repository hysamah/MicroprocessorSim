#include "SIM.h"

SIM::SIM(const string & name){
	this->program_name = name;
	this->file.open(program_name);
	this->run=1;
	while(!this->file.eof())
		this->file >> instMem;
	this->file.close();
	this->pc = 0;

	
}

void SIM::Run(){
	Instruction *Inst = nullptr;
	while (this->run) {
		Inst = this->instMem.getInst(pc);
		this->pc = Inst->excute(this->pc, this->dataMem, this->run);
		cout << "Done excuting instruction" << endl<< endl;
	}
}

SIM::~SIM(){
}