#include "JPA.h"


JPA::JPA(vector <Operand> rs): Instruction(rs)
{
	if(rs.size() != 1)
        throw invalid_argument("Invalid parameter list, JPA instruction takes exactly 1 parameter");
}

void JPA::print() {

	cout << "JPA ";
	for (Operand o : op)
		cout << o.getValue() << " ";
	cout << endl;
}

int JPA::excute(int pc, DataMem &data, bool& running) {
	int jpc;
	jpc=op.at(0).getValue();

	return jpc;
}

JPA::~JPA()
{
}