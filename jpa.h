#pragma once
#include "instruction.h"
#include <iostream>
using namespace std;

class jpa : protected instruction
{
public:
	jpa(vector <int>);
	int excute(int, datamem &);
	void print();
	~jpa();

private:

};

jpa::jpa(vector <int> rs)
{
	for (int x : rs)
	{
		operand q(0, x);
		op.push_back(q);
	}
}

void jpa::print() {

	cout << "JPA ";
	for (operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int jpa::excute(int pc, datamem &data) {
	int jpc;
	jpc=data.get(op.at(0).getValue());

	return jpc;
}

jpa::~jpa()
{
}