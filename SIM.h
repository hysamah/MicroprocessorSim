#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "InstMem.h"

using namespace std;
class SIM //class for simulating the microprocessor
{
private:
	ifstream file;  //file that contains the instructions 
	string program_name; 
	InstMem instMem;  //intruction memory object for this simulator
	DataMem dataMem; //data memory object for this simulator
	int pc; //program counter 
	bool run; 


public:
	SIM(const string & name); //contructor 
	void Run(); //running order 
	void print(string, string);
	~SIM();
};

#endif 