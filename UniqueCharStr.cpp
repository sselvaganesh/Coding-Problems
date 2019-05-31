#include<iostream>
#include<string>
#include<bitset>

bool isAllCharUnique(const std::string& input){

	std::bitset <26> charPos;
	charPos.reset();

	for(int i=0; i<input.length(); i++){

		unsigned num = (input[i]-'a')%26;

		if(charPos[num]){
			return false;
			}
		else {
			charPos.set(num);
			}

		}

	return true;


}

int main(){

	std::string input = "selva";

	bool output = isAllCharUnique(input);

	std::cout << std::boolalpha << output << std::endl;

	return 0;

}
