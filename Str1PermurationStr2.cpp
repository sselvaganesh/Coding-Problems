#include<iostream>
#include<string>
#include<vector>

std::vector<int> getCharCount(const std::string& input){

	std::vector<int> CharCount(26, 0);

	for(int i=0; i<input.length(); i++){
		CharCount.at( (input[i]-'a') %26)++;
		}

	return CharCount;
}


bool compare(const std::vector<int>& s1Map, const std::vector<int>& s2Map){

	for(int i=0; i<s1Map.size(); i++){

		if(s1Map[i] != s2Map[i]){
			return false;
			}

		}

	return true;

}


bool isPermutation(const std::string& s1, const std::string& s2){

	if((s1.length()==0 && s2.length()==0) || s1==s2){
		return true;
		}
	else if(s1.length()==0 && s2.length()>0){
		return false;
		}
	else if(s1.length()>0 && s2.length()==0){
		return false;
		}
	
	std::vector<int> s1Map(26, 0), s2Map(26, 0);
	
	s1Map = getCharCount(s1);
	s2Map = getCharCount(s2);

	return compare(s1Map, s2Map);

}

int main(){

	std::string input1 = "selva", input2 = "aslve";

	bool output = isPermutation(input1, input2);

	std::cout << std::boolalpha << output << std::endl;

	return 0;
}
