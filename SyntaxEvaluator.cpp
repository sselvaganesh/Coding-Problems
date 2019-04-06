#include<iostream>
#include<stack>
#include<vector>

bool evaluate(std::string input){

	std::stack<int> container;

	std::string open = "([{";
	std::string close = ")]}";


	for(int i=0; i<input.length(); i++){

		if(open.find(input[i]) != std::string::npos){
			container.push(open.find(input[i]));
			}
		else {

			if(container.empty() || container.top() != close.find(input[i])){
					return false;
					}
			else {
				container.pop();
				}

			}


		}


	if(container.empty()){
		return true;
		}
	else {
		return false;
		}

}


int main(){

	std::vector<std::string> inputs = { "([])[]({})", "([)]", "((()", "", "((((", ")))))", "(", ")" };

	for(int i=0; i<inputs.size(); i++){
		std::cout << inputs[i] << " : " << std::boolalpha << evaluate(inputs[i]) << std::endl;
		}

}







