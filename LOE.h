#ifndef LOE_H
#define LOE_H
#include "Instruction.h"
using namespace std;

class LOE : protected Instruction
{

public:
    LOE(vector<Operand>);
    //Sets the third address to 1 if the first address value is less
    //than or equal the second address
    int excute(int, DataMem &);
	void print();
    ~LOE();

};

#endif