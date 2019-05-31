#include<iostream>
#include<string>
#include<bits/stdc++.h>

bool isPalindrome(const std::string& input){

	for(int i=0, j=input.length()-1; j>i; i++, j--){

		if(input[i]!=input[j]){
			return false;
			}
		
		}

	return true;
}

bool helper(std::string strInput){
	
	std::string input = strInput;

	do{
		if(isPalindrome(input)){
			std::cout << "Palindrome string: " << input << std::endl;
			return true;
			}

		}while(next_permutation(input.begin(), input.end()));

	return false;

}

void lowerCase(std::string& input){

	for(int i=0; i<input.length(); i++){

		if(input[i]>='A' && input[i]<='Z'){			
			input[i] = (input[i]-'A')%26+'a';
			}

		}

}


bool isPermPalindrome(const std::string& input){

	if(input.length()==0){
		return false;
		}

	std::string inpCopy;		
	int start, pos=0;
	start = input.find_first_not_of(" ", 0);
	pos = input.find_first_of(" ", start);

	while(pos != std::string::npos){
		inpCopy = inpCopy + input.substr(start, pos-start);
		start=pos+1;
		start = input.find_first_not_of(" ", start);
		pos = input.find_first_of(" ", start);
		}

	inpCopy+=input.substr(start);

	lowerCase(inpCopy);

	return helper(inpCopy);

}

int main(){

	std::string input = "Tact Coa";

	std::cout << std::boolalpha << isPermPalindrome(input) << std::endl;

	return 0;
}


