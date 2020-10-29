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
	file >> Q;
	Q.print();





	/*instMem mem();
	datamem dta;
	vector <int> opss = { 1,2 };
	neg n(opss);
	cout << dta.get(1)<<endl;
	n.excute(0, dta);
	cout<<dta.get(1)<<endl;*/
	system("pause");
}