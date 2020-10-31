#include "HLT.h"
HLT::HLT(vector<Operand> pars)
    : Instruction(pars)
{
    if(pars.size() != 0)
        throw invalid_argument("Invalid parameter list, HLT instruction takes no parameters");
}


int HLT::excute(int pc, DataMem& dm, bool& running){
    running = 0;
    cout << "Excution stopped at instuction #"<<pc<<endl;
    return pc + 1;
}

void HLT::print() {

	cout << "HLT ";
	cout << endl;
}
HLT::~HLT(){
}