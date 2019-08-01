#include<iostream>
#include<string>
#include<unordered_set>

typedef std::unordered_set<std::string> dictWords;

bool isMeaningfulWord(const std::string& input, const dictWords& dictionary){

	if(dictionary.find(input) == dictionary.end()){
		return false;
		}
	else {
		return true;
	}

}


void helper(const std::string& input, const dictWords& dictionary, int curPos, std::string curOutput, std::string& fnlOutput){

	static bool isCompleted = false;

	if(curPos>=input.length()){
		isCompleted=true;
		fnlOutput = curOutput;
		return;
		}


	int step=1;
	std::string tempOutput = curOutput;
	
	while(input.length()>= (curPos+step) && !isCompleted){

		if( isMeaningfulWord (input.substr(curPos, step), dictionary) ){

			tempOutput = tempOutput + " " +  input.substr(curPos, step);

			helper(input, dictionary, curPos+step, tempOutput, fnlOutput);

			if(isCompleted){
				return;
				}
			else {
				tempOutput = curOutput;				
				}

			}

		step++;

		}

		
}

std::string getLine(const std::string& input, const dictWords& dictionary){

	std::string fnlOutput;

	helper(input, dictionary, 0, "", fnlOutput);

	return fnlOutput;

}

int main(){


	std::string input = "meetmenow"; 

	dictWords dictionary = {"meet", "ow", "me", "now", "men"};	

	std::string output = getLine(input, dictionary);	

	std::cout << input << '\t' << output << std::endl;

	return 0;
}

