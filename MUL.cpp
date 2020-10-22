#include "MUL.h"

MUL::MUL(vector <Operand> rs): Instruction(rs)
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, MUL instruction takes exactly 3 parameters");
    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, both paramaters in NEG must be variables");    
}

void MUL::print() {

	cout << "MUL ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int MUL::excute(int pc, DataMem &data) {

	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	data.setVar(op.at(2).getValue(), a0*a1 );
	return pc + 1;
}

MUL::~MUL()
{
}