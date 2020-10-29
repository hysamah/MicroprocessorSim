#ifndef JP0_H
#define JP0_H
#include "Instruction.h"
using namespace std;
class JP0 : public Instruction
{

public:
    JP0(vector<Operand>);
    //Jumps to the value in the 2nd operand that correspons to an index in the instruction memory
    //if the 1st operand is equal to 0
    int excute(int pc, DataMem& dm, bool& running);
	void print();
    ~JP0();

};

#endif