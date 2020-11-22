#ifndef LOE_H
#define LOE_H
#include "Instruction.h"
using namespace std;

//derived functionn from instruction class for LOE
class LOE : public Instruction
{

public:
    LOE(vector<Operand>);
    //Sets the third address to 1 if the first address value is less
    //than or equal the second address
    int excute(int, DataMem &, bool& running, int);
	stringstream print();
    ~LOE();

};

#endif