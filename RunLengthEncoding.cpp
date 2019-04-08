#include<iostream>
#include<string>

std::string decode(const std::string& input){

	if(input.length()==0){
		return "";
		}

	std::string output;
	unsigned count;
	std::string::size_type sz;
	count = std::stoi(input, &sz);

	while(count>0){
		output = output+input[sz];
		count--;
		}

	output = output + decode(input.substr(sz+1));

	return output;	

}

std::string encode(const std::string& input){


	std::string output;

	unsigned count = 1;
	char curChar = input[0];

	for(int i=1; i<input.length(); i++){
		
		if(input[i] != input[i-1]){
			output = output + std::to_string(count) + curChar;
			curChar=input[i];
			count=1;	
			}
		else {
			count++;
			}
		

		}

	output = output + std::to_string(count) + curChar;

	return output;
	
}




int main(){


	std::string inputStr = "AAAABBBCCDAASSSSSSSSSSS";
	std::string encodedStr = encode(inputStr);
	std::cout << "Encoding: " << inputStr << '\t' << encodedStr << std::endl;

	std::string decodedStr = decode(encodedStr);
	std::cout << "Decoding: " << encodedStr << '\t' << decodedStr << std::endl;

}
