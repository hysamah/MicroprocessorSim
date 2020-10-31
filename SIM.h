#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "InstMem.h"

using namespace std;
class SIM
{
private:
	ifstream file;
	string program_name;
	InstMem instMem;
	DataMem dataMem;
	int pc;
	bool run;


public:
	SIM(const string & name);
	void Run();
	~SIM();
};

#endif // !ADD_H