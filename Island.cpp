#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> twoDimIntVec;

void checkLands(twoDimIntVec& input, int row, int col){

	//Out of bound condition
	if(row<0 || col<0 || row>=input.size() || col>=input.size() || input[row][col]!=1){
		return;
		}

	input[row][col]=0;

	checkLands(input, row-1, col);
	
	checkLands(input, row, col-1);

	checkLands(input, row+1, col);

	checkLands(input, row, col+1);	
	
}


int calcIslands(const twoDimIntVec& island){

	twoDimIntVec input = island;

	int totalIslands = 0;

	for(int i=0; i<input.size(); i++){


		for(int j=0; j<input[i].size(); j++){

			if(input[i][j]==1){
				totalIslands++;
				checkLands(input, i, j);
				}

			}

		}

	return totalIslands;		

}

int main(){


	twoDimIntVec input = { 	{1, 1, 1, 1, 1},
				{1, 0, 0, 0, 1},
				{1, 0, 0, 0, 1},
				{1, 0, 0, 0, 1},
				{1, 1, 1, 1, 1}
					};

	int totIslands = calcIslands(input);

	std::cout << "Total Islands: " << totIslands << std::endl;


	return 0;
}

