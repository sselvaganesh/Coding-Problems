#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>


typedef std::vector<int> oneDimVec;
typedef std::unordered_map<int, bool> boolMap;

bool lookupElem(oneDimVec& input, int k){

	boolMap myMap;

	for(int &val: input){
		
		int diff = abs(k-val);

		if(myMap[diff]){			
			return true;
			}

		else {
			myMap[val] = true; 
			}

		}

	return false;

}


int main(int argc, char const *argv[]){


	oneDimVec input = {10, 15, 3, 7};
	int k=100;


	bool result = lookupElem(input, k);
	
	std::cout << "Element found: " << result <<std::endl;

	return 0;

}
