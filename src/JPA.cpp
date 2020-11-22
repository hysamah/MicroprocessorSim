#include "JPA.h"


JPA::JPA(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 1)
        throw runtime_error("Invalid parameter list, JPA instruction takes exactly 1 parameter");
}

stringstream JPA::print() //function to print the instruction
{
	stringstream stream;
	stream << "JPA ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;
//	cout << stream.str();
	return stream;

}

int JPA::excute(int pc, DataMem &data, bool& running, int thrd) //execution function for JPA
{
	stringstream stream;
	int jpc;
	jpc = op[0].getValue();

	stream << "Thread #" << thrd << endl;
	stream << "Instruction #"<<pc << " will jump to position " <<jpc<<endl;
	
	cout << stream.str();
	return jpc;
}

JPA::~JPA()
{
}