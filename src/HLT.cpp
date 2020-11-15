#include "HLT.h"
HLT::HLT(vector<Operand> pars)  //construction and parameter validation
    : Instruction(pars)
{
    if(pars.size() != 0)
        throw invalid_argument("Invalid parameter list, HLT instruction takes no parameters");
}


int HLT::excute(int pc, DataMem& dm, bool& running) //function to excute HLT instruction, making the value of "running" into false to stop the program
{
    running = 0;
    cout << "Excution stopped at instuction #"<<pc<<endl;
    return pc;
}

void HLT::print() //function to print the instruction
{

	cout << "HLT ";
	cout << endl;
}
HLT::~HLT(){
}