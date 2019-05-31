#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

typedef std::unordered_map<int, std::vector<std::string>> intStrHashMap;
typedef std::vector<std::string> strVec;

void print(const strVec& input){

	for(auto val: input){
		std::cout << val << ", ";
		}
	
	std::cout << std::endl;
}

strVec helper(const strVec& inp1, const strVec& inp2){

	strVec output;

	for(auto val1: inp1){

		for(auto val2: inp2){

			output.push_back(val1+val2);

			}
		}

	return output;

}


strVec getCharComb(int inpNum, const intStrHashMap& input){

	strVec output;

	if(inpNum/10==0){

		if(input.find(inpNum)==input.end()){
			return output;
			}
		else {
			return input.at(inpNum);
			}

		}

	std::string inputNum = std::to_string(inpNum);

	int val1 = std::stoi(inputNum.substr(0,1));
	int val2 = std::stoi(inputNum.substr(1,1)); 

	output = helper(input.at(val1), input.at(val2));

	for(int i=2; i<inputNum.length(); i++){

		int tempVal = std::stoi(inputNum.substr(i,1));

		if(input.find(tempVal) != input.end()){
			output = helper(output, input.at(tempVal));
			}

		}


	return output;

}

int main(){

	intStrHashMap input;
	input[2] = {"a", "b", "c"};
	input[3] = {"d", "e", "f"};

	strVec output = getCharComb(222, input);

	print(output);

	return 0;

}
