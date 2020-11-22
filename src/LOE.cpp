#include "LOE.h"

LOE::LOE(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, LOE instruction takes exactly 3 parameter");
    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in LOE must be variables"); 
}

stringstream LOE::print() //function to print the instruction
{
	stringstream stream;
	stream << "LOE ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;
//	cout << stream.str();
	return stream;

}

int LOE::excute(int pc, DataMem &data, bool& running, int thrd) //execution function for LOE
{
	stringstream stream;
	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	data.setVar(op.at(2).getValue(), a0<=a1 );

	stream << "Thread #" << thrd << endl;
	stream << "Instruction #"<<pc << " set the data at address " <<op.at(2).getValue()<<
	" with 1 if the data at address " <<op.at(0).getValue()<<
	" value: "<< a0<< " is less than the data at address " << op.at(1).getValue()<< 
	" value: "<< a1<< endl;
	
	cout << stream.str();
	return pc+1;
}

LOE::~LOE()
{
}