#include<iostream>
#include<string>

std::string shortest(std::string str1, std::string str2){

	if(str1.length()<str2.length()) {
		return str1;
		}
	else if(str2.length() < str1.length()) {
		return str2;
		}
	else {

		for(int i=0; i<str1.length(); i++){

			if(str1[i]==str2[i]){
				continue;
				}
			else if(str1[i]<str2[i]){
				return str1;
				}
			else {
				return str2;
				}

			}

		return str1;
		
		}

}

bool isPalindrome(std::string str){

	for(int i=0, j=str.length()-1; j>i; i++, j--){

		if(str[i]!=str[j]){
			return false;
			}
		}

	return true;

}

std::string helper(std::string input, int idx){

	if(isPalindrome(input)){
		return input;
		}

	if(input[idx]==input[input.length()-1-idx]){
		return helper(input, idx+1);
		}

	else {

		std::string input1=input, input2=input;

		auto itr1 = input1.begin()+idx;
		input1.insert(itr1, input1[input1.length()-1-idx]);
			
		auto itr2=input2.end()-idx;
		input2.insert(itr2, input2[idx]);	

		return shortest(helper(input1, idx+1), helper(input2, idx+1));

		}


}


std::string getPalindrome(std::string input){

	return helper(input, 0);	

}


int main(){

	std::string input = "google";

	std::string output = getPalindrome(input);

	std::cout << "Input: " << input << '\t' << "Output: " << output << std::endl;

}
