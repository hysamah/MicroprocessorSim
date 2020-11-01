#include "DataMem.h"



DataMem::DataMem()  //class constructor, allocated memory for 1024 data values
{
    this->Data = new int[1024];
}



void DataMem::setVar(int var, int val) //function to assign a certain value to a certain memory location
{

    cout << "location "<< var<< " is set to to "<< val<<endl;
	this->Data[var] = val;
	this->Init[var] = 1;
}

int DataMem::getVar(int var)  //getter function to retrieve a certain value from the data memory
{
	if (!this->Init[var]) throw runtime_error("The variable " + to_string(var) + " is not initialized");
    cout << "retrieving from location "<< var<< " the value "<< this->Data[var]<<endl;
	return (this->Data[var]);
}

void DataMem::print() //function to print the entire data memory
{
    cout << "-----------------------------------------\n** Data Memory Values **\nVariable ==> Value\n";
    

	for (int i = 0; i<1024; i++) {
		if (this->Init[i]) {
			cout << i << " ==> ";
			cout << this->Data[i] << endl;
		}
	}
	cout << "-----------------------------------------\n";
}

DataMem::~DataMem(){
    cout << "Deleting the data memory"<<endl;
    delete[] this->Data;
}