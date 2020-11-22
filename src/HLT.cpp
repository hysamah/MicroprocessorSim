#include "HLT.h"
HLT::HLT(vector<Operand> pars)  //construction and parameter validation
    : Instruction(pars)
{
    if(pars.size() != 0)
        throw invalid_argument("Invalid parameter list, HLT instruction takes no parameters");
}


int HLT::excute(int pc, DataMem& dm, bool& running) //function to excute HLT instruction, making the value of "running" into false to stop the program
{
    stringstream stream;

    running = 0;
    stream << "Excution stopped at instuction #"<<pc<<endl;
    cout << stream.str();
    return pc;
}

stringstream HLT::print() //function to print the instruction
{
    stringstream stream;

    stream << "HLT ";
	stream << endl;
//    cout << stream.str();
	return stream;

}
HLT::~HLT(){
}