#include<iostream>
#include<vector>

typedef std::vector<int> oneDimIntVec;

bool helper(const oneDimIntVec& input, int pos, int count){

	if(count>1){
		return false;
		}	
	else if(pos==(input.size()-1)){
		return true;
		}


	if(input[pos] < input[pos+1]){
		return helper(input, pos+1, count);
		}
	else {
		return helper(input, pos+1, count+1);
		}


}

bool nonDecreasing(const oneDimIntVec& input){

	if(input.empty()){
		return true;
		}

	return helper(input, 0, 0);

}


int main(){

	oneDimIntVec input = {4, 1, 2, 3, 0};

	std::cout << "Can make it as Non-Decreasing.?: " <<std::boolalpha << nonDecreasing(input) << std::endl;

	return 0;
}
