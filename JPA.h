#ifndef JPA_H
#define JPA_H


#include "Instruction.h"
#include <vector>
#include <iostream>
using namespace std;
//derived functionn from instruction class for JPA
class JPA : public Instruction
{
public:
	JPA(vector <Operand>);
	int excute(int, DataMem &, bool& running);
	void print();
	~JPA();

private:

};
#endif // !JPA_H

