#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<std::vector<int>> twoDimIntVec;
typedef std::vector<int> oneDimIntVec;

void print(const twoDimIntVec& input){

	for(auto eachRow: input){

		for(auto val: eachRow){
			std::cout << val << '\t';

			}
		std::cout << std::endl;
		}

	std::cout << std::endl;
}

twoDimIntVec helper(const twoDimIntVec& input, oneDimIntVec& rows, oneDimIntVec& cols){

	twoDimIntVec output = input;

	std::vector<int>::iterator rowItr, colItr;

	//Rows to Zero
	for(int i=0; i<input.size(); i++){
		rowItr = std::find(rows.begin(), rows.end(), i);

		if(rowItr!=rows.end()){
			output[i].assign(output[i].size(), 0);		
			}
		for(int j=0; j<input[i].size(); j++){

			colItr = std::find(cols.begin(), cols.end(), j);

			if(colItr!=cols.end()){
				output[i][j]=0;
				}

			}
	
		}

	return output;

}

twoDimIntVec checkZeros(const twoDimIntVec& input){

	oneDimIntVec zeroCol, zeroRow;

	for(int i=0; i<input.size(); i++){

		for(int j=0; j<input[i].size(); j++){

			if(input[i][j]==0){
				zeroRow.push_back(i);
				zeroCol.push_back(j);
				}

			}

		}


	return helper(input, zeroRow, zeroCol);


}


int main(){

	twoDimIntVec input = {
				{0, 1, 2},
				{3, 0, 5},
				{6, 7, 0}
					};


	twoDimIntVec output = checkZeros(input);

	print(input);
	print(output);
	
	return 0;
}

