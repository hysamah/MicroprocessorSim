#include "LOE.h"

LOE::LOE(vector <Operand> rs): Instruction(rs)
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, LOE instruction takes exactly 3 parameter");
    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in LOE must be variables"); 
}

void LOE::print() {

	cout << "LOE ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int LOE::excute(int pc, DataMem &data, bool& running) {
	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	data.setVar(op.at(2).getValue(), a0<=a1 );

	return pc+1;
}

LOE::~LOE()
{
}