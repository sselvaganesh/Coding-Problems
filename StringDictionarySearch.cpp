#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

void printOutput(std::vector<std::string>& words){

	for(std::string &word: words){
		std::cout << word <<std::endl;
	}
}


void printDict(std::unordered_map<std::string, std::vector<std::string>>& inpDict){

	for(auto& strVec: inpDict){
		std::cout << "Key: " << strVec.first << std::endl;
		printOutput(strVec.second);
		}

}

void preProcess(std::string input[], std::unordered_map<std::string, std::vector<std::string>>& dict, int arrLen){

	if(arrLen==0){
		return;
		}

	std::string tempString = input[arrLen-1];
	int strLen=tempString.length();

	if(strLen==0){
		return;
		}
	
	while(strLen>0){

		std::vector<std::string> temp;
		std::string key = tempString.substr(0, strLen);

		if(dict.find(key) != dict.end()){			
			temp = dict[key];
			temp.push_back(tempString);
			dict[key] = temp;
			}
		else {
			temp.push_back(tempString);
			dict[key] = temp;
			}
		strLen--;

		}

		std::vector<std::string> temp;

		if(dict.find("") != dict.end()){			
			temp = dict[""];
			temp.push_back(tempString);
			dict[""] = temp;
			}
		else {
			temp.push_back(tempString);
			dict[""] = temp;
			}

	preProcess(input, dict, arrLen-1);

}

std::vector<std::string> getDictWords(std::string prefix, std::unordered_map<std::string, std::vector<std::string>>& dict){

	std::vector<std::string> output;

	if(dict.find(prefix) != dict.end()){
		return dict[prefix];

		}
	else {
		return output;
		}

}

int main(){

	std::unordered_map<std::string, std::vector<std::string>> dictionary;

	std::string inputStrings[] = {"dog", "deer", "deal"};
	int arrLen = sizeof(inputStrings)/sizeof(inputStrings[0]);

	preProcess(inputStrings, dictionary, arrLen);

	//printDict(dictionary);	

	std::cout << "Enter prefix: " ;

	std::string prefix;
	getline(std::cin, prefix);

	if(prefix== ""){
		printOutput(dictionary[""]);
		}
	else {
		std::vector<std::string> output = getDictWords(prefix, dictionary);
		printOutput(output);
		}

	return 0;
}
