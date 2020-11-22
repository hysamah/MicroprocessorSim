#include "JP0.h"
JP0::JP0(vector<Operand> rs) //construction and parameter validation
    : Instruction(rs)
{
    if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, JP0 instruction takes exactly 2 parameters");

    if(rs[0].getType()||rs[1].getType())
        throw invalid_argument("Invalid parameter list, all paramaters in JP0 must be variables"); 
}


int JP0::excute(int pc, DataMem& dm, bool& running, int thrd)//execution function for JP0
{
    stringstream stream;

	int a0 = dm.getVar(op[0].getValue());
    int a1 = op[1].getValue();
	stream << "Thread #" << thrd << endl;
    string decision = (a0 == 0)? "jump" : "not jump";
    stream << "Instruction #"<<pc << " will " <<decision<<" to position " <<a1<<endl;
    cout << stream.str();
    return (a0 == 0)? a1 : pc + 1;
}

stringstream JP0::print() //function to print the instruction
{
    stringstream stream;
	stream << "JP0 ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;
    
    //cout << stream.str();
	return stream;

}

JP0::~JP0(){
}