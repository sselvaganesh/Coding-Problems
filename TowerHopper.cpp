#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;

bool helper(oneDimVec& input, int remTowers, int idx){

	if(remTowers<=0){
		return true;
		}


	for(int i=input[idx]; i>0; i--){

		bool allTowerJumped = helper(input, remTowers-i, idx+i);

		if(allTowerJumped){
			return true;
			}
		}

	return false;

}

bool hopper(oneDimVec& input){

	return helper(input, input.size(), 0);

}

int main(){

	oneDimVec input = {};	//Towers=6

	std::cout << "Is hoppable.? : " << std::boolalpha << hopper(input) << std::endl;

	return 0;
}
