#include<iostream>
#include<vector>
#include<unordered_map>
#include<tuple>

typedef std::vector<std::vector<int>> twoDimVec;
typedef std::vector<int> oneDimArr;
typedef std::unordered_map<int, bool> myMap;
typedef std::tuple<int, int> myTup;
const int arbitaryMaxVal = 99;


myTup getNextEdge(const twoDimVec& edges, const myMap& primsMap, int origin){

		myTup allVisited = std::make_tuple(arbitaryMaxVal, arbitaryMaxVal);
		int curMinDist = arbitaryMaxVal;
		int curMinIdx = arbitaryMaxVal;


		for(int i=origin, j=0; j<edges[origin].size(); j++){

			if(i!=j && (primsMap.count(j)==0 || primsMap.at(j)==false) && edges[origin][j] < curMinDist){								
				curMinDist = edges[origin][j];
				curMinIdx = j;
				}

			}

		if(curMinIdx!=arbitaryMaxVal){
			myTup lowestEdge = std::make_pair(curMinIdx, curMinDist);
			return lowestEdge;
			}

		else{
			return allVisited;
			}


};


void primsMST(const twoDimVec& edges, int initVrtx){

	myMap primsMap;

	int vrtx1 = initVrtx;		
	int vrtx2 = -1;	
	int totVrtx = edges.size();
	int edgesExplored=0;
	
	primsMap[initVrtx]=true;
	int totWeight=0;
	int dist1 = arbitaryMaxVal;
	int dist2 = arbitaryMaxVal;
	myTup edge1, edge2;


	while(edgesExplored < (totVrtx-1)){	

		edge1 = getNextEdge(edges, primsMap, vrtx1);
		dist1 = std::get<1>(edge1);

		if(vrtx2!=-1){					
			edge2 = getNextEdge(edges, primsMap, vrtx2);	
			dist2 = std::get<1>(edge2);
			}


		if(dist1 < dist2){
			std::cout << vrtx1 << '\t' << std::get<0>(edge1) << "\t Distance:"<< dist1<< std::endl;

			if(vrtx2==-1){
				vrtx2=std::get<0>(edge1);
				primsMap[vrtx2]=true;	
				}
			else {

 				vrtx1=std::get<0>(edge1);
				primsMap[vrtx1]=true;	

				}

			totWeight+=dist1;		
			}
		else {

			std::cout << vrtx2 << '\t' << std::get<0>(edge2) << "\t Distance:"<< dist2 << std::endl;

 			vrtx2=std::get<0>(edge2);
			totWeight+=dist2;
			primsMap[vrtx2]=true;	
			}
	
		edgesExplored++;

	}

	std::cout << "MST Distance: " << totWeight <<std::endl;

}


int main(){

	

	twoDimVec input = { 
				{99,  3,   99,  2,   99,  99,  99,  99,  4 },
				{3,   99,  99,  99,  99,  99,  99,  4,   99},
				{99,  99,  99,  6,   99,  1,   99,  2,   99},
				{2,   99,  6,   99,  1,   99,  99,  99,  99},
				{99,  99,  99,  1,   99,  99,  99,  99,  8 },
				{99,  99,  1,   99,  99,  99,  8,   99,  99},
				{99,  99,  99,  99,  99,  8,   99,  99,  99},
				{99,  4,   2,   99,  99,  99,  99,  99,  99},
				{4,   99,  99,  99,  8,   99,  99,  99,  99}
			};

	int startVrtx = 0;

	primsMST(input, startVrtx);

	return 0;
}


