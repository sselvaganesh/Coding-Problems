#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;

void print(const oneDimIntVec& input){

	for(const int& val : input){
		std::cout << val << '\t';
		}
	std::cout << std::endl;
}


bool matching(const oneDimIntVec& input1, const oneDimIntVec& input2, int start){

	int i, j;

	for(i=0, j=start; i<input1.size() && j<input2.size(); i++, j++){

		if(input1[i] != input2[j]){
			return false;
			}
		}

	if(i==input1.size()){
		return true;
		}
	else {
		return false;
		}


}


int checkRotation(const oneDimIntVec& input1, const oneDimIntVec& input2){

	oneDimIntVec arr1 = input1, arr2=input2;

	arr2.insert(arr2.end(), arr2.begin(), arr2.end());

	for(int i=0; i<input2.size(); i++){

		if(input2[i]==input1[0]){

			if(matching(arr1, arr2, i)){
				return i;
				}			

			}

		}	

	return -1;
}


int main(){


	oneDimIntVec input1 = {1, 2, 3, 4}, input2={1, 2, 3, 4};

	int noOfRotation = checkRotation(input1, input2);

	std::cout << "No of rotation: " << noOfRotation << std::endl;

	return 0;
}
