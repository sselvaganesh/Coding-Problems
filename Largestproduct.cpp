#include<iostream>
#include<vector>
#include<math.h>

typedef std::vector<int> oneDimIntVec;


long long largestProduct(const oneDimIntVec& input){

	long long result=0, temp=1;


	for(int i=0; i<pow(2, input.size()); i++){

		int count=0, temp=1;

		for(int j=0; j<input.size(); j++){

			if(i & (1<<j)){
				count++;
				temp= temp*input[j];
				}

			}
		if(count==3 && temp>result){
			result=temp;
			}
	
		}

	return result;

}


int main(){

	oneDimIntVec input = {-10, -10, 5, 2};

	std::cout << largestProduct(input) << std::endl;

	return 0;
}

