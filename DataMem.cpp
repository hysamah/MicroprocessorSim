#include "DataMem.h"



DataMem::DataMem()
{
    this->Data = new int[1024];
    this->allocated = 0;
}

void DataMem::allocate(int var){
    if(this->VarToLoc.find(var) == this->VarToLoc.end()){
        if(this->allocated == 1024){
            throw overflow_error("Unable to allocate new space for a new variable, size reached 1024");
        }
        else{
           // this->Data[this->allocated] = new int;
            this->Init[this->allocated] = 0;
            this->VarToLoc[var] = this->allocated;
            this->allocated++;
        }
    }
}

void DataMem::setVar(int var, int val){
	//this->Data[this->VarToLoc[var]] = new int;
    //(this->Data[this->VarToLoc[var]]) = val;
    //this->Init[this->VarToLoc[var]] = 1;
	(this->Data[var]) = val;
	this->Init[var] = 1;
}

int DataMem::getVar(int var) {
    /*if(!this->Init[this->VarToLoc[var]]) throw runtime_error("The variable " + to_string(var) + " is not initialized");
    return (this->Data[this->VarToLoc[var]]);*/
	if (!this->Init[var]) throw runtime_error("The variable " + to_string(var) + " is not initialized");
	return (this->Data[var]);
}

void DataMem::print(){
    cout << "-----------------------------------------\n** Data Memory Values **\nVariable --> Value\n";
    /*for(auto i = this->VarToLoc.begin(); i != this->VarToLoc.end(); i++){
        cout << i->first << " --> ";
        if(this->Init[i->second]){
            cout << this->Data[i->second] << endl;
        }
        else cout << "uninitialized" << endl;
    }*/

	for (int i = 0; i<1024; i++) {
	
		
		if (this->Init[i]) {
			cout << i << " --> ";
			cout << this->Data[i] << endl;
		}
		//else { cout << i << " --> "; cout << "uninitialized" << endl;}
	}
}

DataMem::~DataMem(){
    for(int i = 0; i < this->allocated; i++){
        delete this->Data;
    }
    delete[] this->Data;
}