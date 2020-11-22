#include "ASI.h"
ASI::ASI(vector<Operand> rs) //construction and parameter validation
    : Instruction(rs)
{
    if(rs.size() != 2)
        throw invalid_argument("Invalid parameter list, ASI instruction takes exactly 2 parameters");
    if(rs[1].getType())
        throw invalid_argument("Invalid parameter list, the 2nd paramater in ASI must be a variable"); 
}


int ASI::excute(int pc, DataMem& dm, bool& running) //execution function for ASI
{
    stringstream stream;

    stream.clear();
	int a0 = op[0].getValue();
    dm.setVar(op[1].getValue(), a0);

    stream << "Instruction #"<<pc << " set the data at address " <<op[1].getValue()<<
	 " with the data =  " <<a0<<endl;

    cout << stream.str();
    stream.clear();
    return pc + 1;
}
stringstream ASI::print() //function to print the instruction
{
    stringstream stream;

    stream.clear();
	stream << "ASI ";
	for (Operand o : op)
		stream << o.getValue() << " ";
	stream << endl;
//    cout << stream.str();
    stream.clear();
	return stream;

}

ASI::~ASI(){
}
