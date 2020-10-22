#ifndef JMP0_H
#define JMP0_H
#include "Instruction.h"
using namespace std;
class JMP0 : public Instruction
{

public:
    JMP0(vector<Operand>);
    //Jumps to the value in the 2nd operand that correspons to an index in the instruction memory
    //if the 1st operand is equal to 0
    int execute(int pc, DataMem& dm);
    ~JMP0();

};

#endif