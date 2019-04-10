#include<iostream>
#include<vector>

int max(int i, int j){

	return (i>j?i:j);

}

int helper(int input[], int len){

	//Base conditions
	if(len==0){
		return 0;
		}
	else if(len ==1){
		return input[0];
		}
	else if(len==2){
		return max(input[0], input[1]);
		}

	return max( input[0]+helper(input+2, len-2), helper(input+1, len-1) );
	
}


int sumOfNonAdjacent(int input[], int len){

	return helper(input, len);

}

int main(){

	int input[] = {4, 3, 2, 1, 10, 8};

	int sum = sumOfNonAdjacent(input, sizeof(input)/sizeof(int));

	std::cout << "Sum: " << sum << std::endl;

}
