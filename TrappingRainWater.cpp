#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;

int min(int val1, int val2){

	return val1<val2?val1:val2;

}

unsigned calcCapacity(const oneDimVec& input){

	if(input.size() < 3){
		return 0;		
		}

	int sum=0, idx=0, lMax=input[0], capacity=0, totCap=0;
	
	for(int i=1; i<input.size(); i++){

		if(idx>0 && (min(lMax, input[i]) * idx )>sum){
			capacity = ( min(lMax, input[i]) * idx ) - sum;
			}

		if(input[i]>=lMax){
			totCap=totCap+capacity;
			capacity=0;
			lMax=input[i];
			sum=0;
			idx=0;
			}

		else {	
			idx++;
			sum = sum+input[i];
			}

		}

	return (totCap+capacity);

}


int main(){

	oneDimVec input = {2, 1, 2}, input1={3, 0, 1, 3, 0, 5}, input2 = {3, 0, 1, 3, 5, 1}, input3={5, 3, 2, 1}, input4={1, 2, 3, 4, 5}, input5={0, 0, 0};

	unsigned capacity = calcCapacity(input1);

	std::cout << "Max Capacity: " << capacity << std::endl;

}
