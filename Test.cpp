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



	//string data;
	//string tmp;
	//while (!file.eof()) {
	//	getline(file, tmp);
	//	data += tmp + '\n';
	//}


	//vector <vector<char *>> instructions;
	//vector <char *> k;
	//char **C, **F;
	//C = new char *;
	//F = new char*;
	//char* tok;
	//char *m;
	//tok = strtok_s(&data[0], "\n", C);
	//while (tok != NULL) {
	//	m = strtok_s(tok, " ", F);
	//	while (m != NULL) {
	//		k.push_back(m);
	//		m = strtok_s(NULL, " ", F);
	//	}
	//	instructions.push_back(k);
	//	k.clear();
	//	tok = strtok_s(NULL, "\n", C);
	//}

	//vector<operand> OP;
	//enum names
	//{
	//	ADD= 68, NEG=71, ASI=73, JP0=48, JPA=65, LOE=69, MUL=76, HLT=84
	//};

	//for (vector<char *> s : instructions)
	//{
	//	
	//	for (int i = 1; i < s.capacity(); i++) {
	//		if (string(s[i-1]) == "ASI") {
	//			operand O(1, atoi(s[i]));
	//			OP.push_back(O);
	//		}
	//		else {
	//			operand O(0, atoi(s[i]));
	//			OP.push_back(O);
	//		}
	//	}
	//	//cout << int(string(s[0]).back()) <<endl;

	//	switch (int(string(s[0]).back()))
	//	{
	//	case ADD:

	//		break;
	//	case NEG:
	//		break;
	//	case MUL:
	//		break;
	//	case HLT:
	//		break;
	//	case JP0:
	//		break;
	//	case JPA:
	//		break;
	//	case ASI:
	//		break;
	//	case LOE:
	//		break;

	//	default:
	//		cout << "invalid instruction" << endl;
	//		break;
	//	}
	//	
	//}




	/*for (char * s : one) {
		tok= strtok_s(s, " ", C);
		while (tok != NULL) {
			k.push_back(tok);
			tok = strtok_s(NULL, " ", C);
		}
		instructions.push_back(k);
		k.clear();
	}*/


	/*instMem mem();
	datamem dta;
	vector <int> opss = { 1,2 };
	neg n(opss);
	cout << dta.get(1)<<endl;
	n.excute(0, dta);
	cout<<dta.get(1)<<endl;*/
	system("pause");
}