#include<iostream>

template <class T1>

T1* cons(T1 val1, T1 val2){

	T1* valArr = new T1[2];

	valArr[0] = val1; 
	valArr[1] = val2; 	

	return valArr;
}

template <class T1>

T1 car(T1* input){
	return (input[0]);

}


template <class T1>

T1 cdr(T1* input){
	return (input[1]);
}


int main(){

	std::string x="SELVA", y="GANESH";

	std::cout << car(cons(x, y)) << std::endl;
	std::cout << cdr(cons(x, y)) << std::endl;

	return 0;

}
