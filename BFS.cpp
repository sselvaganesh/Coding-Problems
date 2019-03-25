#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<unordered_map>

typedef std::tuple<int, int> myTuple;
typedef std::vector<std::tuple<int, int>> tupleVec;
typedef std::queue<int> myQueue;
typedef std::unordered_map<int, bool> myMap;


int getOrigin(myTuple tupPoint){

	return (std::get<0>(tupPoint));
}



int getDest(myTuple tupPoint){

	return (std::get<1>(tupPoint));
}


int getMyAdjacentVertex(myTuple tupPoint, int root){

	int first = std::get<0>(tupPoint);

	if(first==root){
		return (std::get<1>(tupPoint));
	
		}
	else{
		return -1;
		}

}


void bfs(const tupleVec& input, int start){

		myQueue bfsQueue;
		myMap bfsMap;
		int curStart = start;
		
		bfsQueue.push(curStart);
		bfsMap[curStart]=true;

		std::cout<< curStart <<'\t';

		while(!bfsQueue.empty()){

			for(auto &edge: input){

				int origin = getOrigin(edge);
				int des = getDest(edge);

				//std::cout << origin << '\t' << des << std::endl;
					
				if(origin==curStart && bfsMap.count(des)==0){			
					std::cout<< des <<'\t';
					bfsQueue.push(des);
					bfsMap[des]=true;
					}

				}

			bfsQueue.pop();
			curStart = bfsQueue.front();

		}	

	//std::cout <<std::endl;	

	return;

}

//	2 0, 3, 1

int main(int argc, char const *argv[]){


	tupleVec edges = { 	std::make_tuple(0, 1),
				std::make_tuple(0, 2),
				std::make_tuple(1, 2),
				std::make_tuple(2, 0),
				std::make_tuple(2, 3),
				std::make_tuple(3, 3)
			};	

	int startVertex = 2;

	bfs(edges, startVertex);

	std::cout <<std::endl;	
	
	return 0;

}
