#ifndef ASI_H
#define ASI_H
#include "Instruction.h"
using namespace std;
class ASI : public Instruction
{

public:
    ASI(vector<Operand>);
    //Jumps to the value in the 2nd operand that correspons to an index in the instruction memory
    //if the 1st operand is equal to 0
    int execute(int pc, DataMem& dm);
    ~ASI();

};

#endif