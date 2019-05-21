#include<iostream>
#include<vector>

typedef std::vector<int> intVec;

void print(const intVec& input){

	for(int val: input){
		std::cout << val << '\t';
		}

	std::cout << std::endl;

}

int getPIndex(intVec& input, int low, int high){

	int pivot = input[high];
	int pIndex = low;

	for(int i=low; i<high; i++){

		if(input[i]<=pivot){
			std::swap(input[i], input[pIndex]);
			pIndex++;
			}

		}

	std::swap(input[pIndex], input[high]);

	return pIndex;

}

int helper(intVec& input, int low, int high, int n){

	int pIndex = getPIndex(input, low, high);

	if(pIndex==n-1){
		return input[pIndex];
		}

	else if(pIndex>n-1){
		return helper(input, low, pIndex-1, n);
		}

	else {
		return helper(input, pIndex+1, high, n);
		}

}


int nthStat(intVec& input, int n){

	return helper(input, 0, input.size()-1, n);

}

int main(){

	intVec input = {9, 1, 6, 3, 2, 5, 8, 7, 4};

	int val = nthStat(input, 3);

	//print(input);
	std::cout << val << std::endl;

}

