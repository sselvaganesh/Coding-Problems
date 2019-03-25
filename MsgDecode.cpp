#include<iostream>
#include<string>
#include<unordered_map>

int count = 0;

int doCalc(std::string input, int pos, int length, std::unordered_map<std::string, int>& decodeMap){
	
	if(decodeMap.find(input.substr(pos, length)) != decodeMap.end()){
		return decodeMap[input.substr(pos, length)];
		}
	
	count++;

	if(input[pos] == '0'){
		//decodeMap[input.substr(pos, length)] = 0;
		return 0;
		}

	else if(length <= 0){
		//decodeMap[input.substr(pos, length)] = 1;
		return 1;		
		}

	int result = doCalc(input, pos+1, length-1, decodeMap);

	if(length>=2){

		int temp = std::stoi(input.substr(pos, 2));
		
		if(temp>=10 && temp<=26){
			result += doCalc(input, pos+2, length-2, decodeMap);
			}

		}

	decodeMap[input.substr(pos, length)] = result;

	return result;

}

int decode(std::string input){


	std::unordered_map<std::string, int> decodeMap;


	int len = input.length();
	int pos = 0;

	return doCalc(input, pos, len, decodeMap);

}


int main(){


	std::string input = "1111";

	int noOfDecode = decode(input);

	std::cout << "No of Ways to Decode: " << noOfDecode << std::endl;

	std::cout << "count: " << count << std::endl;

	return 0;
}
