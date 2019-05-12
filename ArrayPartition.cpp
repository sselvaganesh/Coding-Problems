#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>

typedef std::vector<int> oneDimVec;

bool helper(const oneDimVec& input, int splitBal){

	for(int i=0; i<pow(2, input.size()); i++){

		int temp=0;

		for(int j=0; j<input.size(); j++){

			if(i & (1<<j)){
				temp+=input[j];
				}
			}

		if(temp==splitBal){
			return true;
			}

		}

	return false;

}

bool canSplit(const oneDimVec& input){

	int totSum = std::accumulate(input.begin(), input.end(), 0);	

	if(totSum%2==1 || input.size()==1){
		return false;
		}

	else {
		return helper(input, totSum/2);
		}

}

int main(){

	oneDimVec input = {15, 5, 20, 10, 35, 15, 10};		//TRUE
	//oneDimVec input = {15, 5, 20, 10, 35};		//FALSE

	bool isPossible = canSplit(input);

	std::cout << std::boolalpha << isPossible << std::endl;

	return 0;
}

