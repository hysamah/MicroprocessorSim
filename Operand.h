#ifndef OPERAND_H
#define OPERAND_H


#include <vector>
using namespace std;

class Operand //class for operands (instuction arguments) which may be a datamemory location or an immediate integer value
{
public:
	Operand(bool, int v);
	 int getValue() const; //getter for the operand value
	 int getType() const; //getter for the operand type
	~Operand();
private:
	bool type; //if type = 0 Operand is var (memory address) if type=1 then this is imm
	int value;
};
#endif // 
