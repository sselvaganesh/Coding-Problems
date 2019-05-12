#include<iostream>
#include<string>
#include<vector>
#include<tuple>

typedef std::vector<std::vector<char>> twoDimCharVec;
typedef std::tuple<int, int> intTuple;

bool searchWord(const twoDimCharVec& input, const std::string& target, const intTuple& start){

	int t1, t2, tgt;

	//Search Left to Right
	t1 = std::get<0>(start);	
	t2 = std::get<1>(start);

	for(tgt=0; tgt<target.length() && input[t1][t2]==target[tgt] && t2<input[t1].size(); tgt++, t2++){
		}

	if(target[tgt]=='\0'){
		return true;
		}

	//Search Top to Bottom
	t1 = std::get<0>(start);	
	t2 = std::get<1>(start);

	for(tgt=0; tgt<target.length() && input[t1][t2]==target[tgt] && t1<input.size(); tgt++, t1++){
		}		
		
	if(target[tgt]=='\0'){
		return true;
		}

	return false;

}


bool lookup(const twoDimCharVec& input, const std::string& target){

	if(target==""){
		return true;
		}

	intTuple pos = std::make_tuple(-1, -1);

	for(int i=0; i<input.size(); i++){

		for(int j=0; j<input[i].size(); j++){

				if(input[i][j]==target[0]){
					std::get<0>(pos) = i;
					std::get<1>(pos) = j;

					if(searchWord(input, target, pos)){
						return true;
						}

					}

				}

			}

	return false;

}

int main(){


	twoDimCharVec input = {
				{'F', 'A', 'C', 'I'},
				{'O', 'B', 'Q', 'P'},
				{'A', 'N', 'O', 'B'},
				{'M', 'A', 'S', 'S'}
			};

	std::string target = "";

	bool isFound = lookup(input, target);

	std::cout << std::boolalpha << target << " : " << isFound << std::endl;

	return 0;
}
