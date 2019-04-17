#include<iostream>
#include<vector>
#include<math.h>

typedef std::vector<int> vecInt;
typedef std::vector<std::vector<int>> vecOfVecInt;

void print(const vecOfVecInt& input){

	for(vecInt eachVec: input){

		std::cout << " {"; 

		for(int& val: eachVec){
			
			std::cout << val << " ";
			
			}

		std::cout << "} " << std::endl;

		}

}


vecOfVecInt powerSet(vecInt& input){

	vecOfVecInt output;

	for(unsigned i=0; i<pow(2, input.size()); i++){

		vecInt temp;

		for(unsigned j=0; j<input.size(); j++){

			if(i & (1<<j)){
				temp.push_back(input[j]);
				}

			}

		output.push_back(temp);

		}

	return output;

}

int main(){
	
	vecInt input = {1, 2, 3, 4};

	vecOfVecInt output = powerSet(input);

	print(output);

}
