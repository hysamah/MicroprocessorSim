#ifndef ASI_H
#define ASI_H
#include "Instruction.h"
using namespace std;
class ASI : public Instruction
{

public:
    ASI(vector<Operand>);
    //Assigns a constant value to a variable
    int excute(int pc, DataMem& dm, bool& running);
	void print();
    ~ASI();

};

#endif