#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<climits>

typedef std::vector<std::vector<int>> twoDimIntVec;
typedef std::vector<int> oneDimIntVec;
typedef std::tuple<int, int> coOrdinatesTemplate;
typedef std::vector<std::tuple<int, int>> vectorCoordinates;

bool isVisited(const coOrdinatesTemplate& curIndex, const vectorCoordinates& alreadyVisited){

	if(std::find(alreadyVisited.begin(), alreadyVisited.end(), curIndex) == alreadyVisited.end()){
		return false;
		}
	return true;

}

bool isOutOfBound(const coOrdinatesTemplate& curIndex, const twoDimIntVec& input){

	if(std::get<0>(curIndex)<0 || std::get<0>(curIndex)>=input.size() || std::get<1>(curIndex)<0 || std::get<1>(curIndex)>=input[std::get<0>(curIndex)].size()){
		return true;
		}

	return false;
}

bool destinationReached(const coOrdinatesTemplate& curIndex, const twoDimIntVec& input){

	if(input[std::get<0>(curIndex)][std::get<1>(curIndex)]==9){
		return true;
		}

	return false;

}

bool isObstacle(const coOrdinatesTemplate& curIndex, const twoDimIntVec& input){

	if(input[std::get<0>(curIndex)][std::get<1>(curIndex)]!=0){
		return true;
		}

	return false;

}


void helper(const twoDimIntVec& input, coOrdinatesTemplate curIdx, vectorCoordinates visitedIndex, int curPathlen, int& shortestLen){

	if(!isOutOfBound(curIdx, input) && destinationReached(curIdx, input)){
		if(curPathlen<shortestLen){
			shortestLen=curPathlen;
			}
		return;
		}

	if(isOutOfBound(curIdx, input) || isVisited(curIdx, visitedIndex) || isObstacle(curIdx, input) || curPathlen>=shortestLen){
		return;
		}
	

	visitedIndex.push_back(curIdx);	

	//Move Up	
	coOrdinatesTemplate moveUp = std::make_tuple(std::get<0>(curIdx)-1, std::get<1>(curIdx));
	helper(input, moveUp, visitedIndex, curPathlen+1, shortestLen);

	//Move Down
	coOrdinatesTemplate moveDown = std::make_tuple(std::get<0>(curIdx)+1, std::get<1>(curIdx));
	helper(input, moveDown, visitedIndex, curPathlen+1, shortestLen);

	//Move Left
	coOrdinatesTemplate moveLeft = std::make_tuple(std::get<0>(curIdx), std::get<1>(curIdx)-1);
	helper(input, moveLeft, visitedIndex, curPathlen+1, shortestLen);

	//Move Right
	coOrdinatesTemplate moveRight = std::make_tuple(std::get<0>(curIdx), std::get<1>(curIdx)+1);
	helper(input, moveRight, visitedIndex, curPathlen+1, shortestLen);

}


int getShortestpath(const twoDimIntVec& input){

	int shortest=INT_MAX;
	coOrdinatesTemplate origin = std::make_tuple(0, 0);
	vectorCoordinates visitedIndex;

	helper(input, origin, visitedIndex, 0, shortest);

	return shortest;
}



int main(){

	twoDimIntVec input = {
				{0, 1, 1, 1},
				{0, 1, 1, 1},
				{0, 1, 1, 1},
				{0, 0, 0, 9}
			};	

	std::cout << getShortestpath(input) << std::endl;

	return 0;
}
