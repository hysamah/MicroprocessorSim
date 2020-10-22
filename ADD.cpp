#include "ADD.h"

ADD::ADD(vector <Operand> rs): Instruction(rs)
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, ADD instruction takes exactly 3 parameters");
	
}

void ADD::print() {
	
	cout << "ADD ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int ADD::excute(int pc, DataMem &data) {
	float a0 = data.getVar(op.at(0).getValue());
	float a1 = data.getVar(op.at(1).getValue());

	data.setVar(op.at(2).getValue(), a0 + a1);
	return pc + 1;
}

ADD::~ADD()
{
}