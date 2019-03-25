#include<iostream>
#include<vector>


void printValues(std::vector<int> inpVec){


	for(int &val: inpVec){
		std::cout << val << '\t';

	}
	std::cout <<std::endl;

}


int sum(int a, int b){
	return (a+b);
}


void codingProblem( void (*callFunction)(std::vector<int>), std::vector<int> inpVec){

	callFunction(inpVec);

}


int main(){

	std::vector<int> input = {1, 2, 3, 4, 5};

	void (*function1)(std::vector<int>) = printValues;
	
	//function1(input);

	codingProblem(function1, input);

/*

	int (*function2)(int, int) = &sum;
	int result = (*function2)(5, 6);

	std::cout << result << std::endl;

*/
	
	return 0;
}
