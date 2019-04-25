#include<iostream>
#include<string>

bool isPalindrome(const std::string& str){


	for(int i=0, j=str.size()-1; j>i; i++, j--){

		if(str[i]!=str[j]){
			return false;
			}

		}

	return true;

}

std::string max(const std::string& s1, const std::string& s2){

	return s1.size()>s2.size()?s1:s2;
}


std::string helper(const std::string& input, unsigned len){

	if(len==1){
		return input;
		}
	else if(isPalindrome(input)){
		return input;
		}
	
	
	return max( helper(input.substr(1, len-1), len-1), helper(input.substr(0, len-1), len-1) ) ;


}

std::string getLongestPalindrome(const std::string& input){

	return helper(input, input.size());

}

int main(){

	std::string input = "bcdcb";

	std::string output = getLongestPalindrome(input);

	std::cout << "Input: " << input << "\t Output: " << output << std::endl;

}


