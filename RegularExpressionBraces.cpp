#include<iostream>
#include<string>
#include<stack>

typedef std::stack<int> intStack;

bool helper(const std::string& input){

	const static std::string openBraces = "([{";
	const static std::string closeBraces = ")]}";
		
	intStack curStackVal;

	for(int i=0; i<input.length(); i++){

		if(openBraces.find(input[i]) != std::string::npos ){
			curStackVal.push(openBraces.find(input[i]));	
			}
		else {


			if(curStackVal.empty() || curStackVal.top() != closeBraces.find(input[i])){
				return false;			
				}
			else {
				curStackVal.pop();
				}

			}

		}

	if(curStackVal.empty()){
		std::cout << "Valid string: " << input << std::endl;
		return true;
		}
	else {
		//std::cout << "InValid string: " << input << std::endl;
		return false;
		}
	

}


bool isValid(const std::string& input, int pos){

	if(input.length()==0){
		return true;
		}

	else if(pos == input.length()-1 || input.find('*') == std::string::npos ){
		return helper(input);
		}

	std::string tempInput = input;

	for(int i=pos; i<tempInput.length(); i++){

		if(tempInput[i]=='*'){

			std::string inp1 = tempInput.substr(0, i) + '{' + tempInput.substr(i+1);
			std::string inp2 = tempInput.substr(0, i) + '}' + tempInput.substr(i+1);
			
			if( isValid(inp1, i) || isValid(inp2, i) ){
				return true;
				}

			}

		}

	return false;

}


int main(){

	std::string input = "**********";
		
	bool valid = isValid(input, 0);

	std::cout << input << '\t' << std::boolalpha << valid << std::endl;

	return 0;
}

