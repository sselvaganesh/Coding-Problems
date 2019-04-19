#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

typedef std::vector<std::tuple<int, int>> tupVec;
typedef	std::tuple<int, int> intTup;

void print(tupVec& input){

	for(intTup& val: input){

		std::cout << " (" << std::get<0>(val) << " , " << std::get<1>(val) << ") " ; 

		}

	std::cout << std::endl;

}

tupVec getAllLocations(int n){

	tupVec locations;

	for(int i=0; i<n; i++){

		for(int j=0; j<n; j++){

			locations.push_back(std::make_tuple(i, j));

			}
		}

	return locations;

}

int getRow(intTup input){
	return std::get<0>(input);
}

int getCol(intTup input){
	return std::get<1>(input);
}


bool isThreatening(intTup thisLoc, intTup curPos, int n){
	
	if(getRow(thisLoc) == getRow(curPos) || getCol(thisLoc) == getCol(curPos)){
		return true;
		}	
	
	
	//Check Up-left
	intTup temp = curPos;
	while(true){
		
		intTup upLeft = std::make_tuple(std::get<0>(temp)-1, std::get<1>(temp)-1);

		if(getRow(upLeft)<0 || getCol(upLeft)<0){
			break;
			}

		else if(thisLoc==upLeft){
			return true;
			}

		temp = upLeft;		

		}



	//Check Up-right
	temp = curPos;
	while(true){
		
		intTup upRight = std::make_tuple(std::get<0>(temp)-1, std::get<1>(temp)+1);

		if(getRow(upRight)<0 || getCol(upRight)>=n){
			break;
			}

		else if(thisLoc==upRight){
			return true;
			}

		temp = upRight;		

		}


	//Check Down-left
	temp = curPos;
	while(true){
		
		intTup downLeft = std::make_tuple(std::get<0>(temp)+1, std::get<1>(temp)-1);

		if(getRow(downLeft)>=n || getCol(downLeft)<0){
			break;
			}

		else if(thisLoc==downLeft){
			return true;
			}

		temp = downLeft;
		}


	//Check Down-Right
	temp = curPos;
	while(true){
		
		intTup downRight = std::make_tuple(std::get<0>(temp)+1, std::get<1>(temp)+1);

		if(getRow(downRight)>=n || getCol(downRight)>=n){
			break;
			}

		else if(thisLoc==downRight){
			return true;
			}

		temp = downRight;
		}


	return false;	


}

tupVec setLocations(tupVec myLoc, intTup curPos, int n){

	int totSize = myLoc.size();

	for(int i=0; i<myLoc.size(); i++){

		if(isThreatening(myLoc[i], curPos, n)){			
			auto itr = std::find(myLoc.begin(), myLoc.end(), myLoc[i]);
			myLoc.erase(itr);
			i--;
			}		
		}

	return myLoc;

}


bool alreadyExplored(tupVec& visited, intTup pos){

	auto itr = std::find(visited.begin(), visited.end(), pos);

	if (itr!=visited.end()) {
		return true;
		}
	else {

		return false;
		}

}


int helper(tupVec allLocation, tupVec location, tupVec queenLoc, int n, int queen){

	static int printloc=0;

	if(location.empty()){
		return 0;
		}

	queen++;

	int position = 0;
	int itrPos = 0;	
	auto curItr = location.begin() + itrPos;
	
	if(queen==n){
		printloc++;
		queenLoc.push_back(*curItr);
		std::cout << "Position " << printloc << '\t';
		print(queenLoc);
		return location.size();
		}	

	while(curItr!=location.end()){
			
		intTup temp = *curItr;
		queenLoc.push_back(temp);		
		location.erase(curItr);

		tupVec remLocation = setLocations(location, temp, n);

		position += helper(remLocation, remLocation, queenLoc, n, queen);

		queenLoc.erase(queenLoc.end());

		location.erase(location.begin(), location.end());			
		location.assign(allLocation.begin(), allLocation.end());
	
		itrPos++;
		curItr = location.begin() + itrPos;

		}

	return position;

}


int setNQueens(int n){

	//Get all possible places
	tupVec locations, queenLoc;  
	locations = getAllLocations(n);	
	
	return helper(locations, locations, queenLoc, n, 0);


}

int main(){

	int n=4;	
	int output = setNQueens(n);

	std::cout << "Total Possible Combination: " << output << std::endl;

}

