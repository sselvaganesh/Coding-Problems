#include<iostream>
#include<vector>
#include<limits.h>


typedef std::vector<int> oneDimIntVec;

long long int getMaxProduct(const oneDimIntVec& input){

	if(input.size()<2){
		return -1;
		}


	long long int maxProd = LLONG_MIN;

	for(int i=0; i<input.size(); i++){

		for(int j=i+1; j<input.size(); j++){

			//std::cout << input[i] << '\t' << input[j] << '\t' << input[i]*input[j] << std::endl;

			if(maxProd <= (input[i]*input[j])){
				maxProd = input[i]*input[j];
				}

			}

		}
	
	return maxProd;

}


int main(){

	oneDimIntVec input = {1, 4, 3, 6, 7, 0};

	long long int maxProd = getMaxProduct(input);
	
	std::cout << "Max product: " << maxProd << std::endl;

	return 0;
}
