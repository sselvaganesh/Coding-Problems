#include<iostream>

long long unsigned int findHighestOfTwo(long long unsigned int input){

	long long unsigned int output = 1;

	while( (output<<1) <= input){
		output = output << 1;
		}

	return output;

}

int main(){

	long long unsigned int n = 20;

	long long unsigned int highest = findHighestOfTwo(n);

	std::cout << "Input: " << n << "\t Output: " << highest << std::endl;

	return 0;
}
