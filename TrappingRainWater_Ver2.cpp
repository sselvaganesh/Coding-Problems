#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;


int min(const int val1, const int val2){

	return val1 < val2 ? val1 : val2;

}


int findMaxRhtIdx(const oneDimIntVec& input, int curIdx){

	if(curIdx==input.size()-1){
		return -1;
		}

	int maxValIdx=curIdx;

	for(int i=curIdx+1; i<input.size(); i++){

		if(input[i]>input[maxValIdx]){
			maxValIdx=i;
			}

		}

	return maxValIdx;		

}

int calcCapacity(const oneDimIntVec& input){

	if(input.size()<3){
		return 0;
		}

	int totCapacity=0;
	int leftMax=input[0];
	int rightMaxIdx=findMaxRhtIdx(input, 1);

	for(int i=1; i<input.size(); i++){

		if(i>=rightMaxIdx){
			rightMaxIdx=findMaxRhtIdx(input, i);
			}

		if(rightMaxIdx!=-1 && rightMaxIdx>i && leftMax>input[i] && input[rightMaxIdx]>input[i]){			
			totCapacity+= (min(leftMax, input[rightMaxIdx]))-input[i];		
			}
		
		if(input[i]>leftMax){
			leftMax=input[i];
			}

		}


	return totCapacity;
}




int main(){

	oneDimIntVec input = {2, 1, 2}, input1={3, 0, 1, 3, 0, 5}, input2 = {3, 0, 1, 3, 5, 1}, input3={5, 3, 2, 1}, input4={1, 2, 3, 4, 5}, input5={0, 0, 0}, input6={3, 2, 4, 7, 1, 5};

	int capacity = calcCapacity(input5);

	std::cout << "Max Capacity: " << capacity << std::endl;

}
