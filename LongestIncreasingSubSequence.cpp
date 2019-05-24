#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;

void print(const std::vector<int>& input){

	for(int val: input){
		std::cout << val << ", ";
		}
	std::cout << std::endl;
}


std::vector<int> max(std::vector<int> vec1, std::vector<int> vec2){

	return vec1.size()>vec2.size() ? vec1 : vec2;

}


std::vector<int> helper(const int* input, int pos, int len, std::vector<int> curVec){

	if(len==0){
		return curVec;
		}

	oneDimIntVec curVecCopy = curVec;

	if(curVec.size()==0){
		curVec.push_back(input[pos]);
		}
	else {

		int curLastElem = curVec[curVec.size()-1];

		if(curLastElem<input[pos]){
			curVec.push_back(input[pos]);
			}
		
		}

	return max( helper(input, pos+1, len-1, curVec), helper(input, pos+1, len-1, curVecCopy) );


}

std::vector<int> getLongest(const int* input, int len){

	std::vector<int> temp;

	return helper(input, 0, len, temp);

}

int main(){

	
	int input[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	//int input[] = {9, 8, 7, 1, 2, 3};	
	//int input[] = {};
	//int input[] = {9};

	oneDimIntVec output = getLongest(input, sizeof(input)/sizeof(int));

	print(output);

	return 0;
}


