#include<iostream>
#include<vector>
#include<cmath>

typedef std::vector<int> oneDimVec;


void print(oneDimVec &input){

	for(int &val: input){
		std::cout << val << '\t';
		}
	std::cout<<std::endl;

}


void maxHeap(oneDimVec &input, int length, int idx){


	//
	int largest = idx;
	int left  = (2*idx) + 1;
	int right = (2*idx) + 2;


	if(left < length && input[left] > input[largest]){
		largest=left;
		}

	if(right < length && input[right] > input[largest]){
		largest=right;
		}


	if(idx!=largest){
		std::swap(input[idx], input[largest]);
		maxHeap(input, length, idx);
		}

}


void buildMaxHeap(oneDimVec& input){

	int len=input.size();
	
	//find the largest non-leaf node.... floor(n/2)-1;
	for(int i=floor(len/2)-1; i>=0; i--) {
		maxHeap(input, len, i);
		print(input);
		}



	for(int i=len-1; i>=0; i--){
		std::swap(input[0], input[i]);
		maxHeap(input, i, 0);
		}

}




int main(){


	oneDimVec input = {5, 8, 1, 16, 3, 7, 9, 10};

	print(input);
	buildMaxHeap(input);

	return 0;
}


