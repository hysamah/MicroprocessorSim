#include "HLT.h"
HLT::HLT(vector<Operand> pars)
    : Instruction(pars)
{
    if(pars.size() != 0)
        throw invalid_argument("Invalid parameter list, HLT instruction takes no parameters");
}


int HLT::excute(int pc, DataMem& dm, bool& running){
    running = 0;
    return pc + 1;
}


HLT::~HLT(){
}