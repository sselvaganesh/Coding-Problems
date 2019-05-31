#include<iostream>
#include<string>

std::string readN(unsigned int len){

	static const std::string data = "Hello World234!";

	static unsigned int pos = 0;
	
	if(pos>=data.length()){
		return "";
		}	
	
	std::string output = data.substr(pos, len);
	pos+=len;
	return output;

}

int main(){

	for(int i=0; i<3; i++){
		std::cout << readN(5) << std::endl;
		}

	return 0;
}
