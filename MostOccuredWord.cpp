#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

typedef std::vector<std::string> strVec;
typedef std::unordered_map<std::string, int> mapTemplate;

void print(const strVec& input){

	for(const std::string& eachWord: input){
		std::cout << eachWord << '\n';
		}
}


void printDict(const mapTemplate& input){

	for(const auto& eachVal: input){
		std::cout << eachVal.first << '\t' << eachVal.second << std::endl;
		}

}

bool transHelp(const char& eachChar){

	if(eachChar=='\'' || eachChar=='.'){
		return true;
		}
	else {		
		return false;
		}

}

bool isStopWord(const strVec& stopWords, const std::string& input){

	auto itr = std::find(stopWords.begin(), stopWords.end(), input);

	if(itr==stopWords.end()){
		return false;
		}
	else {
		return true;
		}


}

void insert(mapTemplate& wordsCount, const std::string& word, int& maxCount){
	
	auto itr = wordsCount.find(word);

	if(itr==wordsCount.end()){		
		wordsCount[word]=1;
		}
	else {
		wordsCount[word]+=1;

		if(wordsCount[word]>maxCount){
			maxCount=wordsCount[word];
			}

		}

}


mapTemplate splitWords(const std::string& input, const strVec& stopWords, int& maxCount){

	strVec words;
	mapTemplate wordsCount;

	int start = input.find_first_not_of(' ', 0);
	int end = input.find_first_of(' ', start+1);

	std::string tempStr;

	while(start!=std::string::npos && end!=std::string::npos){

		tempStr = input.substr(start, end-start);
		
		if(!isStopWord(stopWords, tempStr)){						
			insert(wordsCount, tempStr, maxCount);
			}

		start = input.find_first_not_of(' ', end+1);
		end = input.find_first_of(' ', start+1);
		}


	if(start!=std::string::npos && !isStopWord(stopWords, input.substr(start))){
		insert(wordsCount, input.substr(start), maxCount);
		}


	return wordsCount;

}


strVec getFinalWords(const mapTemplate& wordsList, const int maxCount){

	strVec output;

	for(const auto& eachWord: wordsList){

		if(eachWord.second==maxCount){
			output.push_back(eachWord.first);
			}

		}


	return output;

}


strVec getStopWords(const strVec& input){

	strVec output;

	for(const std::string& word: input){
		std::string temp;
		temp.resize(word.length());
		std::transform(word.begin(), word.end(), temp.begin(), ::tolower);
		output.push_back(temp);		
		}
	
	return output;

}


strVec highOccurenceWords(const std::string& input, const strVec& stopWordsOrg){

	strVec output;
	int maxCount=0;

	strVec stopWords = getStopWords(stopWordsOrg);
	
	std::string inputStr = input;

	std::transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);

	std::replace_if(inputStr.begin(), inputStr.end(), transHelp, ' ');

	mapTemplate wordsList = splitWords(inputStr, stopWords, maxCount);

	return getFinalWords(wordsList, maxCount);

}






int main(){

	std::string inputStr = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food food  food'.";

	strVec stopWords = {"and", "he", "the", "to", "is", "Jack", "Jill"};

	strVec output = highOccurenceWords(inputStr, stopWords);

	print(output);

}




