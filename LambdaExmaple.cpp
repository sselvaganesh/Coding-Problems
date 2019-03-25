#include<iostream>
#include<vector>


void print(int val){
	std::cout << val << '\t';
}

void printValue(std::vector<int> input, void (*function)(int) ){

	for(int &val: input){
		function(val);
		}

	std::cout << std::endl;

}

int main(){

	std::vector<int> input = {1, 5, 8, 3, 4};

	printValue(input, [](int val){std::cout << val << '\t';} );

	return 0;
}
