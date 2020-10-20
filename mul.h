#pragma once
#include "instruction.h"
#include <iostream>
using namespace std;

class mul : protected instruction
{
public:
	mul(vector <int>);
	int excute(int, datamem &);
	void print();
	~mul();

private:

};

mul::mul(vector <int> rs)
{
	for (int x : rs)
	{
		operand q(0, x);
		op.push_back(q);
	}
}

void mul::print() {

	cout << "MUL ";
	for (operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int mul::excute(int pc, datamem &data) {

	data.set(op.at(2).getValue()) = data.get(op.at(1).getValue()) * data.get(op.at(0).getValue());
	return pc + 1;
}

mul::~mul()
{
}