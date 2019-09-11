#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

void print(const std::unordered_set<std::string>& input){

	for(const std::string& eachWord: input){
		std::cout << eachWord << '\t';
		}

	std::cout << std::endl;
}


std::string sortAsc(const std::string& input){

	std::string temp = input;
	std::sort(temp.begin(), temp.end());
	return temp;
}


std::unordered_set<std::string> getWords(const std::string& input, const std::unordered_set<std::string>& dictionary){

	std::unordered_set<std::string> output;

	std::string inpCopy = input;
	std::sort(inpCopy.begin(), inpCopy.end());

	std::unordered_multimap<std::string, std::string> dictWords;

	for(const std::string& eachWord: dictionary){
		dictWords.insert({sortAsc(eachWord), eachWord});
		}


	for(const auto& eachVal: dictWords){

		if(eachVal.first==inpCopy){
			output.insert(eachVal.second);
			}
		
		}

	return output;

}

int main(){

	std::unordered_set<std::string> dictionary = {"dog", "god", "odd"};
	std::string input = "ogd";

	std::unordered_set<std::string> output = getWords(input, dictionary);

	print(output);

	return 0;
}
