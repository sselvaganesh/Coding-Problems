#include<iostream>
#include<vector>
#include<numeric>

long int mult(int i, int j){
	return (i*j);
}


typedef std::vector<int> oneDimVec;

oneDimVec manipulateElem(const oneDimVec& input){

	long int totlMult = std::accumulate(input.begin(), input.end(), 1, mult);

	oneDimVec output;

	for(int i=0; i<input.size(); i++){
		output.push_back(totlMult/input[i]);
		}

	return output;

}


int main(){

	oneDimVec input = {3, 2, 1};

	oneDimVec result = manipulateElem(input);

	for(int &val: result){
		std::cout << val << '\t';
		}

	std::cout << std::endl;

	return 0;
}
