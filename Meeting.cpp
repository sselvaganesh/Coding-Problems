#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>

typedef std::vector<std::tuple<int, int>> vecTuple;
typedef std::tuple<int, int> tupleArr;
typedef std::unordered_map<int, vecTuple> meetMap;

void printMeeting(const vecTuple& meeting){

	for(int i=0; i<meeting.size(); i++){
		std::cout << "("<< std::get<0>(meeting[i]) << " , " << std::get<1>(meeting[i]) << ") \t";	
		}
	std::cout <<std::endl;

}

void printMeetingGrp(const meetMap& meetGrp){

	for(auto eachGrp: meetGrp){

		std::cout << "Group: " << eachGrp.first << '\t';

		for(auto eachList: eachGrp.second){
			std::cout << "("<< std::get<0>(eachList) << " , " << std::get<1>(eachList) << ") \t";
			}

		std::cout << std::endl;

		}

}

void groupMeeting(std::tuple<int, int> curMeet, meetMap& meetGrp, int& curMaxKey){

	vecTuple temp;

	for(auto eachGrp: meetGrp){

		bool canBeAdded = true;

		for(auto eachList: eachGrp.second){

			if(	std::get<0>(curMeet) >= std::get<0>(eachList) && std::get<0>(curMeet) <= std::get<1>(eachList) || 
				std::get<1>(curMeet) >= std::get<0>(eachList) && std::get<0>(curMeet) <= std::get<1>(eachList) ) {				
				canBeAdded=false;
				break;			
				}

			}

			if(canBeAdded){
				temp = eachGrp.second;
				temp.push_back(curMeet);				
				meetGrp[eachGrp.first] = temp;
				return;	
				}
		}

	temp.push_back(curMeet);
	meetGrp[++curMaxKey] = temp;

}


int minClassRoom(const vecTuple& input){

	if(input.size()==0){
		return 0;
		}
	
	meetMap meetGrp;
	vecTuple tempMeets;
	int curMaxKey=1;

	tempMeets.push_back(input[0]);
	meetGrp[curMaxKey] = tempMeets;

	for(int i=1; i<input.size(); i++){
			groupMeeting(input[i], meetGrp, curMaxKey);
		}


	std::cout << "----- Grouped Meetings ------ " << std::endl;
	printMeetingGrp(meetGrp);
	std::cout << "-----------------------------" << std::endl;

	return meetGrp.size();

}



int main(){

	vecTuple input1, input2, input3, input4, input5;

	input1 = { 	std::make_tuple(30, 75),
			std::make_tuple(0, 50),				
			std::make_tuple(55, 150),
			std::make_tuple(55, 150),
			std::make_tuple(55, 150)
			};

	input2 = { 	std::make_tuple(0, 10),
			std::make_tuple(10, 20),				
			std::make_tuple(20, 30),
			std::make_tuple(30, 40),
			std::make_tuple(40, 50)
			};

	input3 = { 	std::make_tuple(0, 10),
			std::make_tuple(11, 20),				
			std::make_tuple(21, 30),
			std::make_tuple(31, 40),
			std::make_tuple(41, 50)
			};

	input4 = { 	std::make_tuple(30, 75)

			};

	input5 = {};

	std::cout << "Input: ";
	printMeeting(input1);

	std::cout << minClassRoom(input2) << std::endl;





}
