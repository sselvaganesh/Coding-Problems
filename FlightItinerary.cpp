#include<iostream>
#include<tuple>
#include<vector>
#include<string>
#include<algorithm>

typedef std::tuple<std::string, std::string> strTuple;
typedef std::vector<std::tuple<std::string, std::string>> vecStrTuple;
typedef std::vector<std::string> vecStr;
typedef std::vector<bool> boolVec;


void print(const vecStr& input){

	for(std::string val: input){
		std::cout << val << "   ";
		}

	std::cout << std::endl;
}

bool desSort(const strTuple s1, const strTuple s2){
	return std::get<1>(s1) < std::get<1>(s2);
}

int getDest(vecStrTuple& input, boolVec& selection, std::string origin){

	for(int i=0; i<input.size(); i++){

		if(std::get<0>(input[i])==origin && selection[i]==false){
			return i;
			}	
		}
	
	return -1;	

}

bool morePlaces(const boolVec& selection){

	for(bool val: selection){
		
		if(!val){
			return true;
			}

		}

	return false;

}

vecStr getItinerary(const vecStrTuple& input, std::string origin){

	vecStrTuple places = input;
	std::string strOrigin = origin;
	std::sort(places.begin(), places.end(), desSort);
	boolVec selection(places.size(), 0);
	vecStr output;

	output.push_back(strOrigin);

	while(morePlaces(selection)){

		int idx = getDest(places, selection, strOrigin);

		if(idx==-1){
			output.erase(output.begin(), output.end());
			return output;
			}
		else {			
			selection.at(idx)=true;
			output.push_back(std::get<1>(places[idx]));
			strOrigin = std::get<1>(places[idx]);
			}
		}

	if(output.size()==input.size()+1){
		return output;
		}
	else {
		output.erase(output.begin(), output.end());
		return output;
		}

}


int main(){

	vecStrTuple input = {	std::make_tuple("SFO", "HKO"),
				std::make_tuple("YYZ", "SFO"),
				std::make_tuple("YUL", "YYZ"),
				std::make_tuple("HKO", "ORD")
				}; 


	vecStrTuple input1 = {
				std::make_tuple("SFO", "COM"),
				std::make_tuple("COM", "YYZ")
				}; 


	vecStrTuple input2 = {
				std::make_tuple("A", "B"),
				std::make_tuple("A", "C"),
				std::make_tuple("B", "C"),
				std::make_tuple("C", "A")
				}; 


	std::string origin = "A";
	vecStr output = getItinerary(input2, origin);
	print(output);

}
