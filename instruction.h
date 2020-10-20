#pragma once
#include <vector>
#include "operand.h"
#include "datamem.h"

using namespace std;

class instruction 
{
public:
	instruction ();
	virtual void print()=0;
	virtual int excute(int, datamem)=0;
	~instruction ();
	vector <operand> op;
	
private:
	

};

instruction ::instruction ()
{

}

instruction ::~instruction ()
{
}