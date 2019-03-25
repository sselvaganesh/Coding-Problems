#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;


void printVector(const oneDimVec& input){

	for(int val: input){
		std::cout << val <<'\t';
		}

	std::cout << std::endl;

}


oneDimVec doMultiply(const oneDimVec& input){

	oneDimVec arr1, arr2, output;

	//manipulate arr1 elements
	arr1.push_back(1);
	for(int i=1; i<input.size(); i++){
		arr1.push_back(arr1[i-1] * input[i-1]);
		}

	//printVector(arr1);

	//manipulate arr1 elements	
	arr2.push_back(1);
	for(int i=input.size()-2; i>=0; i--){
		int val = arr2.front() * input[i+1];
		arr2.insert(arr2.begin(), val);
		}

	//printVector(arr2);

	//output array	
	for(int i=0; i<arr1.size(); i++){
		output.push_back(arr1[i] * arr2[i]);
		}

	return output;

}

int main(){


	oneDimVec input = {1, 2, 3, 4, 5};

	oneDimVec result = doMultiply(input);

	printVector(result);

	return 0;
}


