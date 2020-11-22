#include <iostream>
#include <future>
using namespace std ;
int shift = 5 ;
int func ( int x, int y ){
	return x + y + shift ;
}

int main (){
	auto t1 = async(launch::async, func, 10 , 4 ) ;
	auto t2 = async(launch::async, func,  15 , 2 ) ;

	int i = t1.get();
	int j = t2.get();

	cout << i << endl;
	cout << j << endl;
	return 0 ;
}