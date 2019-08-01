#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;
typedef std::vector<std::pair<int, int>> intPairObj;


void print(const intPairObj& input){


	for(const auto& eachObj: input){

		std::cout << "(" << eachObj.first << ", " << eachObj.second << "), " << '\t';

		}

	std::cout << std::endl;

}



intPairObj findElemEqualSum(const oneDimIntVec& input1, const oneDimIntVec& input2, int sum){

	intPairObj output;

	if(input1.size()==0 || input2.size()==0){
		return output;
		}


	for(int i=0, j=input2.size()-1; i<input1.size() && j>=0; ){
	
		if(input1[i]+input2[j]==sum){
			std::pair<int, int> temp = std::make_pair(input1[i], input2[j]);
			output.push_back(temp);
			i++; j--;
			}

		else if(input1[i]+input2[j] > sum){
			j--;
			}
		else {
			i++;
			}

		}


	return output;


}




int main(){

	oneDimIntVec arr1 = {1, 2, 3, 4, 5}, arr2 = {5, 6, 7, 8, 9, 10};

	int sum = 12;

	intPairObj output = findElemEqualSum(arr1, arr2, sum);	
	
	print(output);

	return 0;
}
