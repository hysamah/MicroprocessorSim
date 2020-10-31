#include "DataMem.h"



DataMem::DataMem()
{
    this->Data = new int[1024];
    this->allocated = 0;
}



void DataMem::setVar(int var, int val){

    cout << "location "<< var<< " is set to to "<< val<<endl;
	this->Data[var] = val;
	this->Init[var] = 1;
}

int DataMem::getVar(int var) {
	if (!this->Init[var]) throw runtime_error("The variable " + to_string(var) + " is not initialized");
    cout << "retrieving from location "<< var<< " the value "<< this->Data[var]<<endl;
	return (this->Data[var]);
}

void DataMem::print(){
    cout << "-----------------------------------------\n** Data Memory Values **\nVariable --> Value\n";
    

	for (int i = 0; i<1024; i++) {
		if (this->Init[i]) {
			cout << i << " --> ";
			cout << this->Data[i] << endl;
		}
	}
}

DataMem::~DataMem(){
    cout << "Deleting the data memory"<<endl;
    delete[] this->Data;
}