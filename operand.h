#pragma once
#include <vector>
#include "instruction.h"
using namespace std;

class operand
{
public:
	operand(bool, int v);
	const int getType();
	const int getValue();
	~operand();
private:
	bool type; //if type = 0 operand is var (memory address) if type=1 then this is imm
	int value;
};

operand::operand(bool t, int v)
{
	type = t;
	value = v;
}
const int operand::getType() {
	return type;
}
const int operand::getValue() {
	return value;
}

operand::~operand()
{
}