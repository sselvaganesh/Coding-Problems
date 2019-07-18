#include<iostream>

/*
1. write a fn to return the 1's in that numer
2. write a fn to loop from 1 to n and call the numer
	sum up all the count and return
*/


int numOfOnes(int input){

	int count=0, curInp=input;

	while(curInp>0){

		if(curInp%2==1){
			count++;
			}
		curInp/=2;
		}
	
	
	return count;

}


int getBits(int n){

	int totNumOfOnes=0;

	for(int i=1; i<=n; i++){
		totNumOfOnes+=numOfOnes(i);		
		}

	return totNumOfOnes;

}




int main(){

	int totBits = getBits(8);

	std::cout << "Total bits: " << totBits << std::endl;	

	return 0;
}
