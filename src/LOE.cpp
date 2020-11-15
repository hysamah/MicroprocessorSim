#include "LOE.h"

LOE::LOE(vector <Operand> rs): Instruction(rs) //construction and parameter validation
{
	if(rs.size() != 3)
        throw invalid_argument("Invalid parameter list, LOE instruction takes exactly 3 parameter");
    if(rs[0].getType()||rs[1].getType()||rs[2].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in LOE must be variables"); 
}

void LOE::print() //function to print the instruction
{

	cout << "LOE ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int LOE::excute(int pc, DataMem &data, bool& running) //execution function for LOE
{

	set<int, greater<int> >::iterator itr;
	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.lock(*itr);

	int a0 = data.getVar(op.at(0).getValue());
	int a1 = data.getVar(op.at(1).getValue());
	data.setVar(op.at(2).getValue(), a0<=a1 );

	cout << "Instruction #"<<pc << " set the data at address " <<op.at(2).getValue()<<
	" with 1 if the data at address " <<op.at(0).getValue()<<
	" value: "<< a0<< " is less than the data at address " << op.at(1).getValue()<< 
	" value: "<< a1<< endl;


	for (itr = locks.begin(); itr != locks.end(); ++itr)
		data.unlock(*itr);
	
	return pc+1;
}

LOE::~LOE()
{
}