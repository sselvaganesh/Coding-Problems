#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

typedef std::vector<std::vector<int>> matrix;
typedef std::vector<std::pair<int, int>> path;
typedef std::pair<int, int> node;

/*
1. start from the starting pt
2. move in all 4 direction, count the step by +1
	2.1 save the current path already traversed
	2.2 proceed with the non-visited path
3. check outof bound condition, that is, <0 or > size
4. if destination found, save the steps
5. if the cur step is higher than, existing short distance, return and move in other direction


1. fn to check the already visited path
2. fn to check if the pos is out of bound
3. recursive fn to traverse
4. actual fn to formulate the input for the recursive fn and return the output
*/

static int temp=0;

bool isVisited(const path& pathsVisited, const node& curPt){

	auto itr = std::find(pathsVisited.cbegin(), pathsVisited.cend(), curPt);

	if(itr==pathsVisited.end()){
		return false;
		}
	else {
		//std::cout << "isVisited..!"<< std::endl;
		return true;
		}

}

bool checkOutOfBound(const node& curPt, const node& limits){

	if(curPt.first<0 || curPt.first>=limits.first || curPt.second<0|| curPt.second >= limits.second){
		//std::cout << "checkOutOfBound..!"<< std::endl;
		return true;
		}
	else {
		return false;
		}

}

bool canTraverse(const matrix& input, const node& origin, const node& curPt){

	if(input[curPt.first][curPt.second]){
		//std::cout << "canTraverse..!"<< std::endl;
		return false;
		}

	else {
		return true;
		}


	//return !(input[curPt.first][curPt.second]);	
	
}

void helper(const matrix& input, const node& origin, const node startPt, const node& endPt, const node& limits, path nodesTraversed, int& shortestDist, int curSteps){

	if(startPt==endPt){
		if(shortestDist==-1 || curSteps<shortestDist) {
			shortestDist = curSteps;
			}
		return;
		}
	if((origin!=startPt) && (checkOutOfBound(startPt, limits) || isVisited(nodesTraversed, startPt) || !canTraverse(input, origin, startPt) || (shortestDist!=-1 && curSteps>=shortestDist)) ){
		return;
		}

	curSteps++;
	temp++;
	
	nodesTraversed.push_back(startPt);

	//Traverse right
	helper(input, origin, std::make_pair(startPt.first, startPt.second+1), endPt, limits, nodesTraversed, shortestDist, curSteps);


	//Traverse down
	helper(input, origin, std::make_pair(startPt.first+1, startPt.second), endPt, limits, nodesTraversed, shortestDist, curSteps);


	//Traverse up
	helper(input, origin, std::make_pair(startPt.first-1, startPt.second), endPt, limits, nodesTraversed, shortestDist, curSteps);


	//Traverse left
	helper(input, origin, std::make_pair(startPt.first, startPt.second-1), endPt, limits, nodesTraversed, shortestDist, curSteps);

}

int findShortestPath(const matrix& input, const std::pair<int, int>& startPt, const std::pair<int, int>& endPt){

	int shortestDistance = -1;

	path temp;

	node limits = std::make_pair(input.size(), input[0].size());

	helper(input, startPt, startPt, endPt, limits, temp,  shortestDistance, 0);

	return shortestDistance;

}


int main(){

	matrix input = {

			{1, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
					};

	std::pair<int, int> startPt = std::make_pair(0, 0);
	std::pair<int, int> endPt = std::make_pair(0, 2);

	int shortPath = findShortestPath(input, startPt, endPt);

	std::cout << "Shortest Path: " << shortPath << '\t' << "calculations: " <<temp<< std::endl;

	return 0;
}
