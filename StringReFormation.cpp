#include<iostream>
#include<string>
#include<vector>

typedef std::vector<std::string> strVec;

int findDictWord(int itrPos, strVec dictWords, std::string input, int pos){

	int i= ++itrPos;

	for(; dictWords.size()>i; i++){

		if(input[pos]==dictWords[i][0] && dictWords[i]==input.substr(pos, dictWords[i].length() )){
			return i;
			}

		}

	return -1;

}


std::string helper(strVec dictWords, std::string input, int pos, std::string curOutput, bool& isSuccess){

	//Base Condition
	if(pos==input.length()){
		isSuccess = true;
		return curOutput;		
		}
	
	int curDictIdx = findDictWord(-1, dictWords, input, pos);

	while(curDictIdx >= 0){

		std::string tempOutput = curOutput + " " + dictWords[curDictIdx];	
		int len = dictWords[curDictIdx].length();		
		std::string maxPosStr = helper(dictWords, input, pos+len, tempOutput, isSuccess);

		//Identify if all strings are combined.? If yes, Return
		if(isSuccess){
			return maxPosStr;
			}

		curDictIdx = findDictWord(curDictIdx, dictWords, input, pos);
		}	
		
	return " ";

}

std::string strReFormation(strVec dictWords, std::string input){

	if(input.length()==0){
		return NULL;
		}

	unsigned int pos=0;
	std::string output;
	bool isSuccess = false;
	
	return helper(dictWords, input, pos, output, isSuccess);
	
}

int main(){

	strVec dictWords = { "quick", "brown", "the", "fox", "null"};	
	std::string inpStr = "thequickbrownfoxquick";

	//strVec dictWords = { "bed", "bath", "bedbath", "and", "beyond"};
	//std::string inpStr = "bedbathandbeyonds";

	std::string outputStr = strReFormation(dictWords, inpStr);

	std::cout << outputStr << std::endl;

}
