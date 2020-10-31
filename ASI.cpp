#include "ASI.h"
ASI::ASI(vector<Operand> rs)
    : Instruction(rs)
{
    if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, ASI instruction takes exactly 2 parameters");
    if(rs[1].getType())
        throw invalid_argument("Invalid parameter list, the 2nd paramater in ASI must be a variable"); 
}


int ASI::excute(int pc, DataMem& dm, bool& running){
    int a0 = op[0].getValue();
    dm.setVar(op[1].getValue(), a0);

    cout << "Instruction #"<<pc << " set the data at address " <<op[1].getValue()<<
	 " with the data =  " <<a0<<endl;

    return pc + 1;
}
void ASI::print() {

	cout << "ASI ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

ASI::~ASI(){
}
