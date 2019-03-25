#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;


void print(oneDimVec &input){

	for(int &val: input){
		std::cout << val << '\t';

		}
	std::cout << std::endl;

}


void helper(oneDimVec &input, int start, int mid, int end){

	oneDimVec tempVec;
	
	int i=start;
	int j=mid+1;	

	while(i<=mid && j<=end){

		if(input[i]<input[j]){
			tempVec.push_back(input[i]);
			i++;
			}
		else{
			tempVec.push_back(input[j]);
			j++;
			}
		}


	while(i<=mid){
		tempVec.push_back(input[i]);
		i++;
		}

	
	while(j<=end){
		tempVec.push_back(input[j]);
		j++;
		}


	for(int i=0, j=start; i<tempVec.size() && j<=end; i++, j++){		
		input.at(j)=tempVec[i];
		}

	//print(input);

}



void merge(oneDimVec &input, int start, int end){

	//base case
	if(start>=end){
		return;
		}


	int mid = (start+end)/2;

	merge(input, start, mid);
	merge(input, mid+1, end);	
	
	helper(input, start, mid, end);

	//print(input);

}


void mergeSort(oneDimVec &input){

	//prepare inputs
	int end=input.size()-1;
	int start=0;

	merge(input, start, end);

}


int main(){

	oneDimVec input = {8, 3, 10, 2, 6, 1};

	print(input);
	
	mergeSort(input);

	print(input);

	return 0;

}


