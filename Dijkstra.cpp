#include<iostream>
#include<vector>
#include<tuple>
#include<limits.h>

typedef std::vector<bool> boolVec;
typedef std::vector<std::vector<int>> twoDimVec;
typedef std::vector<std::tuple<int, int>> tupVec;

const int maxVal = INT_MAX;

std::tuple<int, int> helper(const twoDimVec& input, const boolVec& vistedVrtx, int curVrtx){

	int nextVrtx=-1;
	int minDist=INT_MAX;
	int tempCnt =0;

	for(int i=0; i<input[curVrtx].size(); i++){

		if(i!=curVrtx && vistedVrtx[i]==false && minDist>input[curVrtx][i]){
			minDist=input[curVrtx][i];
			nextVrtx = i;
			}
		else if(input[curVrtx][i]==INT_MAX){
			tempCnt++;			
			}
		}

	std::tuple<int, int> nextVrtxTup = std::make_tuple(nextVrtx, minDist);
		
	return nextVrtxTup;

}


tupVec getShortestPath(const twoDimVec& input, int initVrtx){

	tupVec output;
	int totVrtx = input.size();
	int curVrtx1 = initVrtx;
	int curVrtx2 = -1;
	int curDist1 = 0;
	int curDist2 = 0;

	boolVec visitedVrtx(totVrtx, false);
	visitedVrtx.at(curVrtx1) = true;

	std::tuple<int, int> nextVrtx1, nextVrtx2; 
	nextVrtx1 = helper(input, visitedVrtx, curVrtx1);

	output.push_back(nextVrtx1);

	curVrtx2 = std::get<0>(nextVrtx1);
	curDist2 = std::get<1>(nextVrtx1);

	visitedVrtx.at(curVrtx2) = true;
	int totVrtxVisited = 2;	
	
	while(totVrtx > totVrtxVisited){
			
		nextVrtx1 = helper(input, visitedVrtx, curVrtx1);
		nextVrtx2 = helper(input, visitedVrtx, curVrtx2);

		int tempDist1 = std::get<1>(nextVrtx1);			
		int tempDist2 = std::get<1>(nextVrtx2);


		if(tempDist1<tempDist2){
			int temp = std::get<0>(nextVrtx1);
			visitedVrtx.at(temp)=true;
			curVrtx1 = temp;

			std::get<1>(nextVrtx1) = tempDist1+curDist1;
			curDist1 = std::get<1>(nextVrtx1);			
			output.push_back(nextVrtx1);		
			
			}
		else if(tempDist1>tempDist2) {
			int temp = std::get<0>(nextVrtx2);
			visitedVrtx.at(temp)=true;
			curVrtx2 = temp;

			std::get<1>(nextVrtx2) = tempDist2+curDist2;
			curDist2 = std::get<1>(nextVrtx2);
			output.push_back(nextVrtx2);
			}
		else {	
		
			for(int i=0; i<visitedVrtx.size(); i++){
				if(!visitedVrtx[i]){
					std::get<0>(nextVrtx1)=i;				
					}
				}
			output.push_back(nextVrtx1);
			}


		totVrtxVisited++;
		}

		return output;
}



int main(){


	twoDimVec input = { 	{maxVal, 	2, 		4, 		maxVal, 	maxVal, 	maxVal},	//0
				{maxVal, 	maxVal, 	1, 		7, 		maxVal, 	maxVal},	//1
				{maxVal, 	maxVal, 	maxVal, 	maxVal, 	3, 		maxVal},	//2
				{maxVal, 	maxVal, 	maxVal, 	maxVal, 	maxVal, 	1},		//3
				{maxVal, 	maxVal, 	maxVal, 	2, 		maxVal, 	5},		//4
				{maxVal, 	maxVal, 	maxVal, 	maxVal, 	maxVal, 	maxVal}		//5
			};

	int initVrtx = 1;

	tupVec result = getShortestPath(input, initVrtx);
	
	std::cout << "Starting Vertex: " << initVrtx << std::endl;

	for(auto &edges: result){
			int vrtx = std::get<0>(edges);
			int dist = std::get<1>(edges);
			std::cout << vrtx << '\t' << dist <<std::endl; 
		}
	
	return 0;
}
