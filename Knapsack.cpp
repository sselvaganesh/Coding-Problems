#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>


typedef std::pair<int, int> pairTemplate;
typedef std::vector<std::pair<int, int>> vecPairTemplate;
typedef std::vector<std::vector<int>> twoDimVec;

typedef struct knapSackTemplate{
	vecPairTemplate profWeight;
	int maxProf;
} knapSack;


void printData(const vecPairTemplate profWeit){
	for(auto &val: profWeit){
			std::cout<<val.first<< '\t'<<val.second <<std::endl;
		}
	std::cout<< "----------" <<std::endl;

}


bool sortWeightAsc(pairTemplate val1, pairTemplate val2){

	return val1.first < val2.first;

	}


int max(int val1, int val2){

	return (val1>val2 ? val1 : val2);

}


int getTbleValue(const twoDimVec& knapSackTble, const vecPairTemplate& profitsWeights, int item, int weight){


	/*   Formula   max{ table[i-1][j]  , table[i-1][weight-Wi]+Profit(i)

	*/

	auto profWt = profitsWeights[item-1];
	std::cout<< item << '\t'<< profWt.first << '\t' << profWt.second << std::endl;

	if(weight-profWt.first < 0){
		return knapSackTble[item-1][weight];
		}
	else {
		return max( knapSackTble[item-1][weight], knapSackTble[item-1][weight-profWt.first]+profWt.second );
		}
	
}



knapSack getItems(const vecPairTemplate& profitsWeights, const twoDimVec& knapSackTble, int row, int col){

	knapSack itemsIncluded;
	
	int maxProfit = knapSackTble[row-1][col-1];	
	itemsIncluded.maxProf = maxProfit;
	int tempRow = row-1;

	while(maxProfit>0){

		auto it = std::find(knapSackTble[tempRow-1].begin(), knapSackTble[tempRow-1].end(), maxProfit);

			if(it == knapSackTble[tempRow-1].end()) {
				itemsIncluded.profWeight.push_back(profitsWeights[tempRow-1]);
				maxProfit -= profitsWeights[tempRow-1].second;
				}
			tempRow--;		
		}

	return itemsIncluded;

}


knapSack doKnapSack(const vecPairTemplate& profitsWeights, const int maxWeight){

	int row = profitsWeights.size()+1;
	int col = maxWeight+1;
	
	twoDimVec knapSackTble(row, std::vector<int>(col, 0));
	

	//Fill KnapSack Table
	for(int i=1; i<row; i++){

		for(int j=1; j<col; j++){

			knapSackTble[i].at(j) = getTbleValue(knapSackTble, profitsWeights, i, j);

			}

		std::cout << "-----------" <<std::endl;

		}
	
	//Traverse table and form final output

	for(auto &trow: knapSackTble){

		for(auto &val: trow){
			std::cout<< val << '\t'; 

			}
			std::cout<<std::endl;

		}


	return getItems(profitsWeights, knapSackTble, row, col);
	

}


int main(int argc, char const *argv[]){

	vecPairTemplate profitsWeights = { 
					std::make_pair(2, 1), 
					std::make_pair(3, 2), 
					std::make_pair(4, 5),
					std::make_pair(5, 6)
						};
	int maxWeight = 8;	

	std::sort(profitsWeights.begin(), profitsWeights.end(), sortWeightAsc);

	printData(profitsWeights);


	knapSack myBag = doKnapSack(profitsWeights, maxWeight);
	
	std::cout<< "------- KnapSack---------" <<std::endl;

	for(auto &val: myBag.profWeight){
		std::cout<< val.first << '\t' << val.second <<std::endl;
		}

	std::cout<< "Max Profit possible: " << myBag.maxProf <<std::endl;

	return 0;
}










