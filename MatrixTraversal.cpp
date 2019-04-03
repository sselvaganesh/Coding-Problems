#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

typedef std::vector<std::vector<bool>> boolMatrix;
typedef std::vector<std::tuple<int, int>> tupleVec;
typedef std::tuple<int, int> tupTemplate;

void printPath(const tupleVec& path, tupTemplate endPt, int steps){

	std::cout << "Tot. Steps: " << steps << "   ";

	for(int i=0; i<path.size(); i++){
		std::cout << "("<< std::get<0>(path[i]) << " , " << std::get<1>(path[i]) << ")" << "  ->  ";
		}
	
	std::cout << " ("<< std::get<0>(endPt) << " , " << std::get<1>(endPt) << ")" << std::endl;

}

bool validateCurPt(tupTemplate point, boolMatrix input){

	int rows = input.size();
	int cols = input[0].size();

	int curRow = std::get<0>(point);
	int curCol = std::get<1>(point);

	if(curRow<0 || curRow>=rows || curCol<0 || curCol>=cols || input[curRow][curCol]){
		return false;
		}

	return true;	
}


bool isReached(tupTemplate point1, tupTemplate endPt){

	//if(std::get<0>(point1) == std::get<0>(endPt) && std::get<1>(point1) == std::get<1>(endPt)){
	if(point1==endPt){
		return true;		
		}
	else {
		return false;
		}
}


bool isVisited(tupTemplate curPos, tupleVec pathSoFar){


	auto itr = std::find(pathSoFar.begin(), pathSoFar.end(), curPos);

	if(itr==pathSoFar.end()){
		return false;
		}
	else {
		return true;
		}

}

void traverse(const boolMatrix& input, tupTemplate startPt, tupTemplate endPt, tupleVec path, int curTotSteps, int& globalMin){

	//BaseCondition
	if(isReached(startPt, endPt)){

		if( globalMin==-1 || curTotSteps<globalMin ){
			globalMin=curTotSteps;
			printPath(path, endPt, curTotSteps);
		}

		return;
		}
	else if(!validateCurPt(startPt, input)){
		return;
		}

	else if(isVisited(startPt, path)){
		return;
		}
	else if(curTotSteps > globalMin && globalMin != -1){
		return;
		}
		
	path.push_back(startPt);
	curTotSteps++;

	//Move in all direction	
	tupTemplate left, right, up, down;
	int xCoOrdinate, yCoOrdinate;

	xCoOrdinate = std::get<0>(startPt);
	yCoOrdinate = std::get<1>(startPt);

	//Left	
	left = std::make_pair(xCoOrdinate, yCoOrdinate-1);
	traverse(input, left, endPt, path, curTotSteps, globalMin);
	
	//Right
	right = std::make_pair(xCoOrdinate, yCoOrdinate+1);
	traverse(input, right, endPt, path, curTotSteps, globalMin);

	//Up
	up = std::make_pair(xCoOrdinate-1, yCoOrdinate);
	traverse(input, up, endPt, path, curTotSteps, globalMin);

	//Down
	down = std::make_pair(xCoOrdinate+1, yCoOrdinate);
	traverse(input, down, endPt, path, curTotSteps, globalMin);

}


signed calcSteps(const boolMatrix& input, tupTemplate startPt, tupTemplate endPt){

	int globalMin = -1;
	int curTotSteps = 0;
	tupleVec path;
	
	traverse(input, startPt, endPt, path, curTotSteps, globalMin);

	return globalMin;

}


int main(){


	boolMatrix inputMat1 ={ {0, 0, 0, 0}, 
				{1, 1, 0, 1}, 
				{0, 0, 0, 0}, 
				{0, 0, 0, 0}
				};
	
	tupTemplate startPt = std::make_pair(3, 0);	
	tupTemplate endPt = std::make_pair(0, 0);

	signed minSteps = calcSteps(inputMat1, startPt, endPt);

	std::cout << "Min Steps Required: " << minSteps << std::endl;

}
