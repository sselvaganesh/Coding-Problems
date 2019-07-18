#include<iostream>
#include<vector>

void print(const std::vector<int>& input){

	for(const int& val :  input){

		if(val>0){
			std::cout << val << '\t';
			}
		}

	std::cout << std::endl;
}


unsigned setInitVal(std::vector<int>& input, int initVal, int partitionVal){
	
	input.push_back(initVal);
	int remVal = partitionVal-initVal;
	unsigned pos=0;	

	while(remVal>0){

		if(remVal>initVal){
			input.push_back(initVal);
			}
		else {
			input.push_back(remVal);
			}

		remVal-=initVal;
		pos++;
		}

	return pos;
}


void helper(std::vector<int>& input, unsigned int curPos){

	print(input);

	while(input[1]>1){

		if(input[curPos]==1){
			curPos--;
			continue;
			}

		input.push_back(1);
		input[curPos]-=1;
		print(input);
		}

}

void partition(const unsigned int n){

	std::vector<int> output;
	output.reserve(n);
	unsigned lastPos;
	
	for(unsigned int i=n; i>0; i--){
		output.clear();
		lastPos = setInitVal(output, i, n);		
		helper(output, lastPos);
		}

}

int main(){

	unsigned int n=9;

	partition(n);

	return 0;
}
