#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
//#include<bits/stdc++.h>


typedef std::vector<std::pair<int, int>> vecPoints;
typedef std::vector<std::tuple<int, int, int>> vecTuple;
typedef std::vector<std::tuple<int, int, int>> vecDistPoints;
typedef std::tuple<int, int, int> tuplePt;

bool ascSort(tuplePt pt1, tuplePt pt2){
	
	int dist1 = std::get<2>(pt1);
	int dist2 = std::get<2>(pt2);

	return dist1 < dist2 ;

}

void checkClosest(vecTuple& output, std::pair<int, int> thisPoint, int dist){

	if(output.size()<2){
		std::tuple<int, int, int> temp;
		std::get<0>(temp) = std::get<0>(thisPoint);
		std::get<1>(temp) = std::get<1>(thisPoint);
		std::get<2>(temp) = dist;
		output.push_back(temp);
		}

	else {

		std::sort(output.begin(), output.end(), ascSort);

		auto lastItem = output.back();
		int curMaxDist = std::get<2>(lastItem);

		if(dist > curMaxDist){
			return;
			}

		else {
			std::get<0>(lastItem) = std::get<0>(thisPoint);
			std::get<1>(lastItem) = std::get<1>(thisPoint);
			std::get<2>(lastItem) = dist;

			output.pop_back();
			output.push_back(lastItem);
			}


		}

	return;

}


vecTuple getClosestPoints(const vecPoints& xyCoordinates, const std::pair<int, int>& vertex, int k){

	vecTuple output;

	for(int i=0; i<xyCoordinates.size(); i++){

		std::pair<int, int> thisPoint = (xyCoordinates[i]);

		int dist = sqrt (pow((thisPoint.first-vertex.first), 2) + pow((thisPoint.second-vertex.second), 2));
		std::cout << dist <<std::endl;

		checkClosest(output, thisPoint, dist);

		}

	return output;

}


int main(){

	int k=2;

	vecPoints xyCoordinates = {	std::make_pair(1, 2),
					std::make_pair(3, -1),
					std::make_pair(2, 1),
					std::make_pair(2, 3)
					};

	std::pair<int, int> vertex(std::make_pair(2,2));

	vecTuple result = getClosestPoints(xyCoordinates, vertex, k);


	for(auto &val: result){
		std::cout<< std::get<0>(val) << '\t' << std::get<1>(val) << '\t' << std::get<2>(val) <<std::endl;
		}


	return 0;
}




