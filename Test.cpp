#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <map>
#include "InstMem.h"
#include "NEG.h"
using namespace std;

void main() {

	ifstream file;
	string name = "C:/Users/Dell/Documents/GitHub/MicroprocessorSim/test.txt";
	file.open(name);
	InstMem Q;
	bool run=true;
	DataMem dta;
	file >> Q;
	file.close();
	Q.print();
	
	int pc = 0;
	Instruction *Inst = nullptr;
	while (run) {
		Inst = Q.getInst(pc);
		pc = Inst->excute(pc, dta, run);
		cout << "Done excuting instruction" << endl;
		Inst->print();
		dta.print();
	}
	



	system("pause");
}