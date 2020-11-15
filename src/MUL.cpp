#include "MUL.h"

MUL::MUL(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, MUL instruction takes exactly 3 parameters");
    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in MUL must be variables");    
}

void MUL::print() //function to print the instruction
{

	cout << "MUL ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int MUL::excute(int pc, DataMem &data, bool& running) //execution function for MUL
{

	set<int, greater<int> >::iterator itr;
	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.lock(*itr);

	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	data.setVar(op.at(2).getValue(), a0*a1 );
	
	cout << "Instruction #"<<pc << " multiplied the data at address " <<op.at(0).getValue()<<
	" value: "<< a0<< " with the data at address " <<op.at(1).getValue()<<
	" value: "<< a1<< " Result = " << a0 * a1<< " saved at " <<op.at(2).getValue()<<endl;


	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.unlock(*itr);
	return pc + 1;
}

MUL::~MUL()
{
}