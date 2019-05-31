#include<iostream>
#include<vector>
#include<tuple>

typedef std::vector<std::vector<int>> twoDimIntVec;
typedef std::tuple<int, int> intTuple;

void print(const twoDimIntVec& input){

	for(auto& eachRow: input){

		for(auto& val: eachRow){

			std::cout << val << '\t';
			}
		std::cout << std::endl;

		}

	std::cout << std::endl;
}

void printTuple(const intTuple& input){

	std::cout << "(" << std::get<0>(input) << ", " << std::get<1>(input) << ")" << std::endl;

}


intTuple getNext(const intTuple& curXY, unsigned int n){

	intTuple newXY;
	std::get<0>(newXY) = std::get<1>(curXY);
	std::get<1>(newXY) = std::get<0>(curXY);
	std::get<1>(newXY) = n-std::get<1>(newXY);

	return newXY;
}

void swapElem(twoDimIntVec& input, const intTuple& initPos, unsigned n){
	
	intTuple curPos = getNext(initPos, n);

	int prevVal =  input[std::get<0>(initPos)][std::get<1>(initPos)], curVal;
	
	while(initPos!=curPos){	
		curVal = input[std::get<0>(curPos)][std::get<1>(curPos)];	
		input[std::get<0>(curPos)].at(std::get<1>(curPos)) = prevVal;
		prevVal = curVal;
		curPos = getNext(curPos, n);
		}

	input[std::get<0>(curPos)].at(std::get<1>(curPos)) = prevVal;

}


twoDimIntVec rotateMatrix(const twoDimIntVec& input){

	twoDimIntVec output;

	if(input.size()<=1){
		return output;
		}

	output = input;

	unsigned n = input.size()-1;

	intTuple curPos = std::make_tuple(0, 0);

	for(int i=0; i<n; i++){
		std::get<1>(curPos) = i;
		swapElem(output, curPos, n);
		}

	return output;

}


int main(){


	twoDimIntVec input = {
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 15, 16}
					};


	twoDimIntVec input1 = {
				{1, 2},
				{3, 4}
					};

	twoDimIntVec output = rotateMatrix(input);

	print(input);	
	print(output);

	return 0;
}
