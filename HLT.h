#ifndef HLT_H
#define HLT_H
#include "Instruction.h"
using namespace std;
class HLT : public Instruction
{

public:
    HLT(vector<Operand>);
    //Assigns a constant value to a variable
    int excute(int pc, DataMem& dm, bool& running);
    ~HLT();

};

#endif