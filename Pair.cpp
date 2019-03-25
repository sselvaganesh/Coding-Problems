#include<iostream>

int* cons(int val1, int val2){ 

	int* arrVal = new int;
	arrVal[0] = val1;
	arrVal[1] = val2;	

	return arrVal;
}


int car(int* input){
	return input[0];
}


int cdr(int* input){
	return input[1];
}


int main(){

	int x=10, y=20;

	std::cout << car(cons(x, y)) << std::endl;	

	std::cout << cdr(cons(x, y)) << std::endl;	

	return 0;
}
