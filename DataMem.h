#pragma once
#include <map>
#include <string>
#include<iostream>

using namespace std;

class DataMem
{
public:
	DataMem();
	int getVar(int) ;
	void setVar(int, int);
	void print();
	void allocate(int var);
	~DataMem();

private:
	int * Data;
	int allocated;
	bool Init[1024];
	map<int,int> VarToLoc;
};
