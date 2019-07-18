#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;

void print(const oneDimIntVec& input){

	for(const int& val :  input){
		std::cout << val << '\t';
		}

	std::cout << std::endl;

}

int nextGreaterValIdx(const oneDimIntVec& input, int start){
	
	if(start>=input.size()-1){
		
		return -1;
		}

	int maxIdx = start+1;

	for(int i=start+2; i<input.size(); i++){

		if(input[i]>input[maxIdx]){
			maxIdx=i;
			}

		}

	return maxIdx;

}

oneDimIntVec getGreatestElem(const oneDimIntVec& input){
	
	oneDimIntVec output;

	if(input.size()==0){
		return output;
		}

	int curMaxIdx = nextGreaterValIdx(input, 0);
	output.push_back(input[curMaxIdx]);

	for(int i=1; i<input.size()-1; i++){
	
		if(i<curMaxIdx){		
			output.push_back(input[curMaxIdx]);
			}

		else {
			curMaxIdx = nextGreaterValIdx(input, i);
			output.push_back(input[curMaxIdx]);
			}	

		}

	output.push_back(-1);

	return output;

}



int main(){

	oneDimIntVec input = {16, 17, 4, 3, 5, 2};

	oneDimIntVec output = getGreatestElem(input);

	print(input);
	print(output);

	return 0;
}
