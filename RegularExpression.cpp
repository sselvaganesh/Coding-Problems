#include<iostream>
#include<string>

bool helper(std::string input, std::string pattern, unsigned strPos, unsigned patPos){

	//Base condition
	if(strPos==input.length() && patPos==pattern.length()){
		return true;
		}

	if(strPos==input.length() && patPos!=pattern.length() && pattern[patPos]!='*'){
		return false;
		}

	else if(pattern[patPos]!= '.' && pattern[patPos]!= '*' && pattern[patPos]!=input[strPos]){		
		return false;
		}

	
	//Recursive calls	
	if(pattern[patPos]=='.'){
		return helper(input, pattern, strPos+1, patPos+1);
		}
	else if(pattern[patPos]!='*'){
		return helper(input, pattern, strPos+1, patPos+1);		
		}

	else {

		if(pattern[patPos+1]=='\0'){
			return true;
			}

	
		int tempStrPos = strPos;

		while(tempStrPos < input.length()){

			bool tempResult = helper(input, pattern, tempStrPos, patPos+1);

			if(tempResult){
				return true;
				}

			tempStrPos++;

			}

		return false;

		}


}


bool validate(std::string input, std::string pattern){

	return helper(input, pattern, 0, 0);
}

int main(){

	std::string inpStr = "*";
	std::string pattern = "*";
	
	bool isMatched = validate(inpStr, pattern);

	std::cout << std::boolalpha << isMatched << std::endl;
	
}
