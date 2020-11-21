#pragma once
#include <mutex>
#include <string>
#include <sstream>
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
	void lock(int);
	void unlock(int);
	~DataMem();

private:
	int * Data;  //dynamic array to save the data
	bool Init[1024]; //boolean array to determine each cell of the data memory is populated or empty
	mutex mtx[1024];
};
#endif // !DATAMEM_H