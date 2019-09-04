#include<iostream>
#include<vector>
#include<unordered_set>


void print(const std::vector<int>& input){


	for(const int& val: input){
		std::cout << val << '\t';
		}
	std::cout << std::endl;

}

std::vector<int> printWeights(const std::vector<int>& input, int max){


	bool resultFound = false;
	int firstWeight;

	std::unordered_set<int> inputMap;

	for(int i=0; i<input.size(); i++){

		if(inputMap.find(max-input[i])==inputMap.end()){
			inputMap.insert(input[i]);
			}
		else {

			if(resultFound){

				if(input[i] > firstWeight || max-input[i]>firstWeight){
					firstWeight = (input[i] > max-input[i]) ? input[i] : (max-input[i]);
					}

				}
			else {
				resultFound=true;				
				firstWeight = (input[i] > max-input[i]) ? input[i] : (max-input[i]);
				}

			inputMap.insert(input[i]);
			}

		}

	if(resultFound){
		return {firstWeight, max-firstWeight};
		}
	else{
		{};
		}
	

}

int main(){

	std::vector<int> input = {0, 10, 20, 30, 40, 50, 60};

	int max=60;

	std::vector<int> output = printWeights(input, max);
	print(output);
	return 0;
}
