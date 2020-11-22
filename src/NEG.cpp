#include "NEG.h"

NEG::NEG(vector<Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, NEG instruction takes exactly 2 parameters");
	if(rs[1].getType()||rs[0].getType())
        throw invalid_argument("Invalid parameter list, both paramaters in NEG must be variables");
}

stringstream NEG::print() //function to print the instruction
{
	stringstream stream;
	stream << "NEG ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;
//	cout << stream.str();
	return stream;
}

int NEG::excute(int pc, DataMem &data, bool& running, int thrd) //execution function for NEG
{
	stringstream stream;
	int a0 = data.getVar(op.at(0).getValue());
	data.setVar(op.at(1).getValue(), -1*a0);
	
	stream << "Thread #" << thrd << endl;
	stream <<  "Instruction #"<<pc << " set the data at address " <<op.at(1).getValue()<<
	" value: "<< a0 << " to the negation: "<< -1*a0 << endl;

	cout << stream.str();
	return pc + 1;
}

NEG::~NEG()
{
}