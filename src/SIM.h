#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <thread>
#include<string>
#include <vector>
#include "InstMem.h"

using namespace std;
class SIM //class for simulating the microprocessor
{
private:
	ifstream file;  //file that contains the instructions 
	int programs_num;
	vector <string> programs;
	InstMem* instMem;  //intruction memory object for this simulator
	DataMem dataMem; //data memory object for this simulator
	int* pc; //program counter 
	bool* run; 
	thread* threads;


public:
	SIM(const vector<string>& ); //contructor 
	void Run(); //running order 
	void RunProgram(int i);
	void printInstructions();
    void printData();

	~SIM();
};

#endif 