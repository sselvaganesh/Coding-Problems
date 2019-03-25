#include<iostream>
#include<string>
#include<bitset>

int count=0;

std::bitset<26> getDistBitSet(std::string str){

	std::bitset<26> bitVar;
	int i=0, len=str.length();

	while(i<len){

		int pos = str[i]%26;
		if(!bitVar[pos]){
			bitVar[pos]=true;
			}
		i++;
		}

	return bitVar;
}

int getCount(std::bitset<26> inputBitSet){
	return inputBitSet.count();

}

std::string max(std::string str1, std::string str2){
	return str1.length()>str2.length()?str1:str2;
}

std::string helper(std::string input, int k, std::string& output){

	//Base conditions
	if(k==0 || input.length()==0){
		return "";
		}
	else if(getCount(getDistBitSet(input))<=k){
			return input;
		}

	count++;

	std::string str2 = max( helper(input.substr(1, input.length()-1), k, output), helper(input.substr(0, input.length()-1), k, output) );
	if(str2.length()>output.length()){
		output=str2;
		}

	return output;

}

std::string findLongest(std::string input, int k){

	std::string temp;

	return helper(input, k, temp);	
	
}

int main(){

	std::string input = "aaaaaaaa";
	int k=1;

	std::cout << findLongest(input, k) << "\t count: " << count << std::endl;

	return 0;
}
