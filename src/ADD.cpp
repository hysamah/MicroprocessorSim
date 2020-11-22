#include "ADD.h"

ADD::ADD(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, ADD instruction takes exactly 3 parameters");
	if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in ADD must be variables"); 
}

stringstream ADD::print() //function to print the instruction
{
	stringstream stream;
	stream << "ADD ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;

	//cout << stream.str();
	//stream.clear();
	return stream;

}

int ADD::excute(int pc, DataMem &data, bool& running, int thrd) //execution function for add
{
	stringstream stream;
	
	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	int a2 = op.at(2).getValue();
	 
	data.setVar(op.at(2).getValue(), a0 + a1);
	stream << "Thread #" << thrd << endl;
	stream << "Instruction #"<<pc << " added the data at address " <<op.at(0).getValue()<<
	" value: "<< a0<< " with the data at address " <<op.at(1).getValue()<<
	" value: "<< a1<< " Result = " << a0 + a1<< " saved at " <<a2<<endl;
	stream << "Done excuting instruction" << endl << endl;
	cout << stream.str();
	
	return pc + 1;
}

ADD::~ADD()
{
}