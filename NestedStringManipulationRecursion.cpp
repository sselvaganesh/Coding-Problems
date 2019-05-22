#include<iostream>
#include<string>

void helper(const std::string& str){

	if(str.find('{')==std::string::npos){
		std::cout << str << std::endl;
		return;
		}	


	int start = str.find('{');
	int end = str.find('}', start);

	std::string beginStr = str.substr(0, start-1);
	std::string endStr = str.substr(end+1);
	std::string words = str.substr(start+1, end-start-1);

	int i=0;
	while(words.find('|', i)!=std::string::npos){
		int pos = words.find('|', i);			
		helper(beginStr+ ' ' + words.substr(i, pos-i) + ' ' +endStr);
		i=pos+1;		
		}

	helper(beginStr + ' ' + words.substr(i) + ' ' + endStr);
		

}

void printLines(const std::string& input){
	
	std::string tempStr = input;

	tempStr[0] = ' ';
	tempStr[tempStr.length()-1] = ' ';

	helper(tempStr);	

}


int main(){

	std::string input = "{ this is a {super|good|nice} place to {visit|live} awesome }";

	printLines(input);

	return 0;

}
