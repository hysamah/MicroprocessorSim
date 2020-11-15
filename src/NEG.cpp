#include "NEG.h"

NEG::NEG(vector<Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, NEG instruction takes exactly 2 parameters");
	if(rs[1].getType()||rs[0].getType())
        throw invalid_argument("Invalid parameter list, both paramaters in NEG must be variables");
}

void NEG::print() //function to print the instruction
{

	cout << "NEG ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int NEG::excute(int pc, DataMem &data, bool& running) //execution function for NEG
{

	set<int, greater<int> >::iterator itr;
	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.lock(*itr);

	int a0 = data.getVar(op.at(0).getValue());
	data.setVar(op.at(1).getValue(), -1*a0);
	
	cout <<  "Instruction #"<<pc << " set the data at address " <<op.at(1).getValue()<<
	" value: "<< a0 << " to the negation: "<< -1*a0 << endl;
	

	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.unlock(*itr);

	return pc + 1;
}

NEG::~NEG()
{
}