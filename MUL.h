#ifndef MUL_H
#define MIL_H


#include "Instruction.h"
#include <iostream>
using namespace std;

class MUL : public Instruction
{
public:
	MUL(vector <Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~MUL();

private:

};
#endif // !MUL_H
