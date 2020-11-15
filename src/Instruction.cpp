  
#include "Instruction.h"

Instruction::Instruction(vector<Operand> _op)
    : op(_op)
{
	for (Operand k : op)
	{
		if (!k.getType())
			locks.insert(k.getValue());
	}
}

void Instruction::lockOperands(DataMem& DM){
    for(auto i : this->locks) DM.lock(i);
}

void Instruction::unlockOperands(DataMem& DM){
    for(auto i : this->locks) DM.unlock(i);
}
Instruction::~Instruction(){

}