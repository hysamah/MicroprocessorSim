#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "SIM.h"
using namespace std;

int main() {

	string printI, printD;
	string program_name;
	vector <string> program_names;
	int nPrograms;
	cout << "Please enter the number of programs to run: \n";
	cin >> nPrograms;
	for (int i = 0; i < nPrograms; i++) {
		cout << "Please enter test program name: \n";
		cin >> program_name;
		program_names.push_back(program_name);
		
	}
	cout << "Would you like to print the entire instruction memories at the end of the program? \n Enter y for yes, any other key for no \n\n";
	cin >> printI;
	cout << "Would you like to print the entire data memory at the end of the program? \n Enter y for yes, any other key for no \n";
	cin >> printD;
	
	
	SIM simulation(program_names);
	
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

	if (printI == "y")
		simulation.printInstructions();
	if (printD == "y")
		simulation.printData();

	system("pause");
	return 0;
}