#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "SIM.h"
using namespace std;

int main() {

	string program_name;
	cin >> program_name;
	
	SIM simulation(program_name);
	
	simulation.Run();
	
	return 0;
}