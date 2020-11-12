#include "JPA.h"


JPA::JPA(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 1)
        throw invalid_argument("Invalid parameter list, JPA instruction takes exactly 1 parameter");
}

void JPA::print() //function to print the instruction
{

	cout << "JPA ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int JPA::excute(int pc, DataMem &data, bool& running) //execution function for JPA
{
	//data.lock(op[0].getValue());
	
	int jpc;
	jpc = op[0].getValue();

	cout << "Instruction #"<<pc << " will jump to position " <<jpc<<endl;
	
	//data.unlock(op[0].getValue());

	return jpc;
}

JPA::~JPA()
{
}