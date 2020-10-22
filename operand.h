#pragma once
#include <vector>
#include "instruction.h"
using namespace std;

class Operand
{
public:
	Operand(bool, int v);
	 int getValue() const;
	 int getType() const;
	~Operand();
private:
	bool type; //if type = 0 Operand is var (memory address) if type=1 then this is imm
	int value;
};

