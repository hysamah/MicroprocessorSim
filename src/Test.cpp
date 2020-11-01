#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "SIM.h"
using namespace std;

int main() {

	string printI, printD;
	string program_name;
	cout << "Please enter test program name: \n";
	cin >> program_name;
	cout << "Would you like to print the entire data memory at the end of the program? \n Enter y for yes, any other key for no \n";
	cin >> printD;
	cout << "Would you like to print the entire instruction memory at the end of the program? \n Enter y for yes, any other key for no \n\n";
	cin >> printI;
	
	SIM simulation(program_name);
	
	try{
		simulation.Run();
	}
	catch(runtime_error &ex){
		cerr << "Runtime Error!!!\n"<<ex.what()<<endl;
	}
	catch(invalid_argument &ex){
		cerr << "Invalid Argument Error!!!\n"<< ex.what()<<endl;
	}
	catch(overflow_error &ex){
		cerr<< "Overflow Error!!!\n"<< ex.what() <<endl;
	}
	catch(...){
		cerr<< "Exception Error!!!\n" <<endl;
	}
	if (printI=="y")
		simulation.printInstructions();
	if (printD=="y")
		simulation.printData();
	
	return 0;
}