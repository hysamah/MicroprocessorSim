#pragma once
#include "Instruction.h"
#include <vector>
#include <iostream>
using namespace std;

class JPA : protected Instruction
{
public:
	JPA(vector <Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~JPA();

private:

};

