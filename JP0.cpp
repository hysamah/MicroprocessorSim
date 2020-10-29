#include "JP0.h"
JP0::JP0(vector<Operand> rs)
    : Instruction(rs)
{
    if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, JP0 instruction takes exactly 2 parameters");

    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in JP0 must be variables"); 
}


int JP0::excute(int pc, DataMem& dm, bool& running){
    int a0 = dm.getVar(op[0].getValue());
    int a1 = op[1].getValue();
    
    return (a0 == 0)? a1 : pc + 1;
}

void JP0::print() {

	cout << "JP0 ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

JP0::~JP0(){
}