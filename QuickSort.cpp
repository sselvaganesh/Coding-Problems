#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;


void print(oneDimVec &input){

	for(int &val: input){
		std::cout << val << '\t';
		}
	std::cout <<std::endl;
}


int setPivot(oneDimVec& input, int start, int end){

	int pivot = input[end];
	int pIndex = start;

	for(int i=start; i<end; i++){

		if(input[i]<=pivot){
			std::swap(input[i], input[pIndex]);
			pIndex++;
			}

		}

	std::swap(input[end], input[pIndex]);

	return pIndex;

}


void quick(oneDimVec& input, int start, int end){

	if(start>=end){
		return;
		}

	int pivot = setPivot(input, start, end);

	quick(input, start, pivot-1);
	quick(input, pivot+1, end);

}


void quickSort(oneDimVec& input){

	//prepate inputs
	int len=input.size();
	int start=0;
	int end=len-1;

	quick(input, start, end);

}


int main(){


	oneDimVec input = { 8, 1, 9, 2, 10, 3, 11, 4, 15};	//{1, 2, 3, 6, 8};	

	print(input);

	quickSort(input);

	print(input);

	return 0;
}
