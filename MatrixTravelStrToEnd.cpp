#include<iostream>
#include<tuple>

void helper(std::tuple<int, int> curPoint, std::tuple<int, int> destination, unsigned& routes){

	if(curPoint==destination){
		routes+=1;		
		}
	else if(std::get<0>(curPoint) > std::get<0>(destination) || std::get<1>(curPoint) > std::get<1>(destination)){
		return;
		}	

	//Moving Right	
	std::tuple<int, int> right = std::make_tuple(std::get<0>(curPoint),   std::get<1>(curPoint)+1);
	helper(right, destination, routes);

	//Moving Down
	std::tuple<int, int> down  = std::make_tuple(std::get<0>(curPoint)+1, std::get<1>(curPoint));
	helper(down, destination, routes);

}

unsigned totRoutes(std::tuple<int, int> matrix){

	std::tuple<int, int> strPoint = std::make_tuple(0, 0);
	std::tuple<int, int> destination = std::make_tuple(std::get<0>(matrix)-1, std::get<1>(matrix)-1);

	unsigned routes = 0;
	helper(strPoint, destination, routes);
	return routes;

}

int main(){


	std::tuple<int, int> matrix = std::make_tuple(5, 5);		//Min Dimension is 2X2

	unsigned noOfWays = totRoutes(matrix);

	std::cout << "Number of routes: " << noOfWays << std::endl;

	return 0;
}
