#pragma once
#include "instruction.h"
#include <iostream>
using namespace std;

class add : protected instruction
{
public:
	add(vector <int>);
	int excute(int, datamem &);
	void print();
	~add();

private:

};

add::add(vector <int> rs)
{
	for (int x : rs)
	{
		operand q(0, x);
		op.push_back(q);
	}
}

void add::print() {
	
	cout << "ADD ";
	for (operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int add::excute(int pc, datamem &data) {

	data.set(op.at(2).getValue()) = data.get(op.at(1).getValue()) + data.get(op.at(0).getValue());
	return pc + 1;
}

add::~add()
{
}