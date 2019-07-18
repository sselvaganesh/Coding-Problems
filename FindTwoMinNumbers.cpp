#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;


void getMin2(const oneDimIntVec& input){

	if(input.size()<2){
		return;
		}


	int min1, min2;

	if(input[0]>input[1]){
		min1 = input[1]; 
		min2 = input[0];					
		}
	else {
		min1 = input[0]; 
		min2 = input[1];					
		}


	for(int i=2; i<input.size(); i++){

		if(input[i]<=min1){			
			min2 = min1;
			min1 = input[i];
			}
		else if(input[i]<=min2){
			min2=input[i];
			}

		}

	std::cout << min1 << '\t' << min2 << std::endl;

}




int main(){

	oneDimIntVec input = {-8, 2, 1, 6, 4, -5};

	getMin2(input);
	
	return 0;
}
