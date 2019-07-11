#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> twoDimIntVec;

void helper(const twoDimIntVec& input, unsigned maxRowIdx, unsigned maxColIdx, unsigned curRow, unsigned curCol, unsigned curCoins, unsigned& maxCoins){

	//Base condition
	if(curRow>maxRowIdx || curCol>maxColIdx){
		return;
		}

		//Add coins at the cur position
	curCoins+=input[curRow][curCol];

	if(curCoins>maxCoins){
		maxCoins=curCoins;
		}

	if(curRow==maxRowIdx && curCol==maxColIdx){
		return;
		}


	//move down
	helper(input, maxRowIdx, maxColIdx, curRow+1, curCol, curCoins, maxCoins);


	//move right
	helper(input, maxRowIdx, maxColIdx, curRow, curCol+1, curCoins, maxCoins);	

}

unsigned int getMaxCoins(const twoDimIntVec& input){
	
	if(input.size()==0){
		return 0;
		}

	unsigned maxRowIdx = input.size()-1;
	unsigned maxColIdx = input[0].size()-1;	
	unsigned curRow = 0, curCol = 0, curCoins=0, maxCoins=0;

	helper(input, maxRowIdx, maxColIdx, curRow, curCol, curCoins, maxCoins);

	return maxCoins;

}

int main(){


	twoDimIntVec input = { 
				{0, 0, 0, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0}
					};


	unsigned int maxCoins = getMaxCoins(input);

	std::cout << "Max Coins: " << maxCoins << std::endl;

	return 0;
}

/*

	1. Get Matrix, always not Empty
	2. Starting point (0, 0) and end point (n, n)
	3. Can move only right and down
	4. Coins cannot have negative values


	1. Explore all possible routes and count coins //Recursive approach
	2. Every step, have 2 possibilities
	3. Check if the step is valid (coordinates are with in n*n)
	4. Replace curmax if the next combination is higher

*/
