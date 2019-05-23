#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>

typedef std::tuple<int, int> myTup;
typedef std::vector<std::tuple<int, int>> tupVec;
typedef std::vector<int> oneDimVec;
typedef std::vector<std::vector<int>> twoDimVec;


bool sortAsc(const myTup& val1, const myTup& val2){
	return std::get<0>(val1)<std::get<0>(val2);
}


int max(int val1, int val2){
	return val1>val2 ? val1 : val2;

}


void print(const twoDimVec& table){


	for(oneDimVec eachRow: table){

		for(int val: eachRow){
			std::cout << val << '\t';
			}

		std::cout << std::endl;
		}

}



int getValue(const twoDimVec& table, const tupVec& input, int row, int col){


	int curWt=std::get<0>(input[row-1]);
	int curPft=std::get<1>(input[row-1]);

	if(col-curWt<0){
		return table[row-1][col];
		}
	else {
		return max( table[row-1][col], table[row-1][col-curWt]+curPft);
		}


}


void getItems(const tupVec& wtprof, const twoDimVec& table, int row, int col){

	int maxProfit = table[row-1][col-1];
	int tempProf = maxProfit;

	std::cout << "Max profit: " << maxProfit << std::endl;

	int curRow=row-1, curCol=col-1;

	while(tempProf>0){

		auto itr = std::find(table[curRow-1].begin(), table[curRow-1].end(), tempProf);

		if(itr==table[curRow-1].end()){
			std::cout << "Items: " << std::get<0>(wtprof[curRow-1]) << '\t';
			tempProf-=std::get<1>(wtprof[curRow-1]);		
			}
		curRow--;

		}

	std::cout << std::endl;


}



void knapsack(const tupVec& wtProf, int capacity){


	tupVec input=wtProf;
	std::sort(input.begin(), input.end(), sortAsc);


	//Create knapsack table
	int row=input.size()+1;
	int col=capacity+1;

	twoDimVec table(row, oneDimVec(col, -1));
	table[0].assign(col, 0);
	

	backTrack(table, input, row-1, col-1);
	print(table);


	//Fill table
	for(int i=1; i<row; i++){

		for(int j=1; j<col; j++){
			table[i].at(j) = getValue(table, input, i, j);
			}

		}


	getItems(input, table, row, col);

	print(table);

}




int main(){


	tupVec input = { std::make_tuple(2, 1),
			 std::make_tuple(3, 2),
			 std::make_tuple(4, 5),
			 std::make_tuple(5, 6)
				};
	int capacity = 8;

	knapsack(input, capacity);

	return 0;
}
