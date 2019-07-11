#include<iostream>
#include<vector>
#include<tuple>

typedef std::vector<int> oneDimIntVec;

void print(const oneDimIntVec& output){

	for(int val: output){
		std::cout << val << '\t';
		}
	std::cout << std::endl;
}


std::tuple<int, int> helper(const oneDimIntVec& input, int idx, bool direction){

	// 0 -> Left ; 1 -> Right
	int resIdx;	

	if(direction){
		resIdx=idx+1;
		}
	else {
		resIdx=idx-1;
		}


	while(true){

		if(resIdx<0 || input.size()<=resIdx || input[resIdx]>input[idx]){
			break;
			}

		if(direction){
			resIdx+=1;
			}
		else {
			resIdx-=1;
			}

		}


	if(resIdx>=0 && input.size()>resIdx){
		return std::make_tuple(input[resIdx], resIdx);
		}
	else {

		return std::make_tuple(-1, -1);
		}

}




oneDimIntVec calculate(const oneDimIntVec& input){

	oneDimIntVec output;
	std::tuple<int, int> tup1, tup2;

	for(int i=0; i<input.size(); i++){

		tup1 = helper(input, i, false);
		tup2 = helper(input, i, true);


		if(std::get<1>(tup1) ==-1 && std::get<1>(tup2)==-1){
			output.push_back(-1);			
			}
		else if(std::get<1>(tup1) ==-1 && std::get<1>(tup2)!=-1){
			output.push_back(std::get<1>(tup2));
			}
		else if(std::get<1>(tup1) !=-1 && std::get<1>(tup2)==-1){
			output.push_back(std::get<1>(tup1));
			}
		else {
			std::get<1>(tup1) < std::get<1>(tup2) ? output.push_back(std::get<1>(tup1)) : output.push_back(std::get<1>(tup2));	

			}
		
		}

	return output;

}



int main(){

	oneDimIntVec input = {1, 4, 2, 1, 7, 6}, output;
	
	output = calculate(input);

	print(output);
	
	return 0;
}
