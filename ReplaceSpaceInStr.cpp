#include<iostream>
#include<string>


std::string replaceSpace(std::string input){

	if(input.find(" ", 0)==std::string::npos){
		return input;
		}

	unsigned pos = input.find(" ", 0);
	
	input = input.substr(0, pos) + "%20" + input.substr(pos+1);

	return replaceSpace(input);

}

int main(){

	std::string input = "Mr Selva Ganesh    ";

	std::string output = replaceSpace(input);
	
	std::cout << input << '\t' << output << std::endl;

	return 0;
}
