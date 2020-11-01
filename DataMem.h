#pragma once
#include <map>
#include <string>
#include<iostream>

using namespace std;

#ifndef DATAMEM_H
#define DATAMEM_H


class DataMem  //data memory class
{
public:
	DataMem();  //class constructor
	int getVar(int) ; //getter that retrieves data from the data memory from a certain location
	void setVar(int, int); //function to set a certain memory location to a certain value
	void print(); //function to print the populated parts of the data memory 
	~DataMem();

private:
	int * Data;  //dynamic array to save the data
	bool Init[1024]; //boolean array to determine each cell of the data memory is populated or empty
};
#endif // !DATAMEM_H