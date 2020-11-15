  
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


Instruction::~Instruction(){

}