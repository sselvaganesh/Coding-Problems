#include<iostream>
#include<vector>
#include<cmath>

typedef std::vector<int> oneDimVec;


void printArray(const oneDimVec& input){

	for(int val: input){
		std::cout << val << '\t';
		}

		std::cout << std::endl;

}

void removeNeg(oneDimVec& input){

	for(auto it=input.begin(); it<input.end(); it++){

		if(*it<=0){
			input.erase(it);
			}

		}

	printArray(input);

}


int findMissingElem(oneDimVec& input){

	//remove negatives and zeros
	removeNeg(input);

	//Assume array element as index and make values to negatives
	for(int i=0; i<input.size(); i++){
		if (abs(input[i])-1 < input.size() && input[abs(input[i])-1] >0){
			input.at(abs(input[i])-1) = -1 * input[abs(input[i])-1];			
			}
		}

	printArray(input);

	//find the first positive value in the array return index+1 || return size+1
	for(int i=0; i<input.size(); i++){
		if(input[i]>0){
			return (i+1);
			}
		}

	return (input.size()+1);	

}


int main(){

	oneDimVec input = {2, 2, 1};

	printArray(input);

	int result = findMissingElem(input);

	std::cout << "Missing Element: " << result << std::endl;

	return 0;
}


