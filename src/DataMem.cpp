#include "DataMem.h"



DataMem::DataMem()  //class constructor, allocated memory for 1024 data values
{
    this->Data = new int[1024];
    for (int i = 0; i<1024; i++) {
        this->Init[i]=0;
    } 
}

void DataMem::lock(int index) {
	this->mtx[index].lock();
}

void DataMem::unlock(int index) {
	this->mtx[index].unlock();
}

void DataMem::setVar(int var, int val) //function to assign a certain value to a certain memory location
{
	stringstream stream;
    stream << "location "<< var<< " is set to to "<< val<<endl;
	cout << stream.str();
	this->Data[var] = val;
	this->Init[var] = 1;

}

int DataMem::getVar(int var)  //getter function to retrieve a certain value from the data memory
{
	stringstream stream;
	//if (!this->Init[var]) throw runtime_error("The variable " + to_string(var) + " is not initialized");
    stream << "retrieving from location "<< var<< " the value "<< this->Data[var]<<endl;
	cout << stream.str();
	return (this->Data[var]);
}

void DataMem::print() //function to print the entire data memory
{
	stringstream stream;
    stream << "-----------------------------------------\n** Data Memory Values **\nVariable ==> Value\n";
    

	for (int i = 0; i<1024; i++) {
		if (this->Init[i]==1) {
			stream << i << " ==> ";
			stream << this->Data[i] << endl;
		}
	}
	stream << "-----------------------------------------\n";
	cout << stream.str();
}

DataMem::~DataMem(){

    cout << "Deleting the data memory\n";
    delete[] this->Data;
}