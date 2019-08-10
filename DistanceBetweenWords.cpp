#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
#include<stack>

typedef std::vector<std::string> vecOfStr;

void print(const vecOfStr& input){

	for(const std::string& eachWord : input){
		std::cout << eachWord << std::endl;
		}

}

vecOfStr split(const std::string& input){

	vecOfStr output;

	if(input.length()==0){
		return output;
		}

	int start=0, pos = input.find(" ", start);

	while(pos!=std::string::npos){
		output.push_back(input.substr(start, pos-start));
		start=pos+1;
		pos=input.find(" ", start);		
		}

	output.push_back(input.substr(start, input.length()-start));

	return output;

}


int getDistance(const std::string& input, const std::string& beginStr, const std::string& endStr){
	
	vecOfStr strWords = split(input);

	if(std::find(strWords.begin(), strWords.end(), beginStr)==strWords.end() || std::find(strWords.begin(), strWords.end(), endStr)==strWords.end()){
		return -1;
		}

	int distance = INT_MAX, temp;

	for(int i=0; i<strWords.size(); i++){

		if(strWords[i]!=beginStr){
			continue;
			}

		temp=0;

		for(int j=i+1; j<strWords.size(); j++){
			
			if(strWords[j]==endStr){

				if(temp<distance){
					distance=temp;
					}

				break;

				}
			else {
				temp++;
				}

			}

		}	


	return distance;

}

int stackDistance(const std::string& input, const std::string& startWord, const std::string& endWord){

	vecOfStr strWords = split(input);

	if(std::find(strWords.begin(), strWords.end(), startWord)==strWords.end() || std::find(strWords.begin(), strWords.end(), endWord)==strWords.end()){
		return -1;
		}


	std::stack<int> posStack;

	int distance = INT_MAX, temp;

	for(int i=0; i<strWords.size(); i++){


		if(strWords[i]==startWord){
			posStack.push(i);
			}

		if(strWords[i]==endWord){

			if(i-posStack.top() < distance){
				distance=i-posStack.top();
				}

			posStack.pop();
			}

		}
	
	return distance-1;	

}


int main(){

	std::string input = "hello dog cat cat dog hello world self cat hello selva world world";

	std::string val1="hello", val2="world";
	
	int distance = getDistance(input, val1, val2);

	std::cout << distance << std::endl;

	int distance2 = stackDistance(input, val1, val2);

	std::cout << distance2 << std::endl;

	return 0;
}
