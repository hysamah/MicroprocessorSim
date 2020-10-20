#pragma once
#include "instruction.h"
#include <iostream>
using namespace std;

class neg : protected instruction
{
public:
	neg(vector <int>);
	int excute(int, datamem &);
	void print();
	~neg();

private:

};

neg::neg(vector <int> rs)
{
	for (int x : rs)
	{
		operand q(0, x);
		op.push_back(q);
	}
}

void neg::print() {

	cout << "NEG ";
	for (operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int neg::excute(int pc, datamem &data) {

	data.set(op.at(1).getValue()) = -data.get(op.at(0).getValue());
	return pc + 1;
}

neg::~neg()
{
}