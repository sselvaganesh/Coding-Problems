#include<iostream>
#include<stack>
#include<tuple>
#include<vector>
#include<unordered_map>

typedef std::tuple<int, int> myTuple;
typedef std::vector<std::tuple<int, int>> tupVec;
typedef std::unordered_map<int, bool> myMap;
typedef std::stack<int> myStack;

int getOrigin(std::tuple<int, int> edge){

	return (std::get<0>(edge));

}


int getDest(std::tuple<int, int> edge){

	return (std::get<1>(edge));

}


void dfs(const tupVec& edges, int startVrtx){

	myStack dfsStack;
	myMap dfsMap;

	int curVrtx = startVrtx;

	dfsStack.push(curVrtx);
	dfsMap[curVrtx] = true;
	std::cout << curVrtx << '\t';

	while(!dfsStack.empty()){


		auto edge=edges.begin();
		for(; edge!=edges.end(); edge++){

			int origin = getOrigin(*edge);
			int dest = getDest(*edge);
		
			if(curVrtx==origin && dfsMap.count(dest)==0){
				std::cout << dest << '\t';
				curVrtx = dest;
				dfsMap[dest]=true;
				dfsStack.push(dest);
				break;
				}
			}

			if(edge==edges.end()){
				dfsStack.pop();

				if(!dfsStack.empty()){
					curVrtx=dfsStack.top();					
					}
				}

		}


	return;
}

int main(){

	tupVec input = {	std::make_tuple(0, 1),
				std::make_tuple(0, 2),
				std::make_tuple(1, 2),
				std::make_tuple(2, 0),
				std::make_tuple(2, 3),
				std::make_tuple(3, 3)
				};

	int startVertex = 2;

	dfs(input, startVertex);

	std::cout <<std::endl;

	return 0;
}
