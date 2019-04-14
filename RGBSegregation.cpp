#include<iostream>
#include<string>

std::string sort1(std::string& input){
	
	int i=0;
	
	for(int j=input.length()-1; j>i ; ){

		while(input[i]=='R' && j>i){
			i++;
			}

		while(input[j]!='R' && j>i){
			j--;
			}


		if(input[i]!='R' && input[j]=='R'){
			std::swap(input[i], input[j]);
			}

		}

	for(int j=input.length(); j>i; ){

		while(input[i]=='G' && j>i){
			i++;
			}

		while(input[j]!='G' && j>i){
			j--;
			}


		if(input[i]!='G' && input[j]!='B'){
			std::swap(input[i], input[j]);
			}

		}

		
	return input;	

}


std::string sort2(std::string& input){


	int r=0, b=input.length()-1;
	int i=0;

	while(b>r && b>i){

		if(input[i]=='R'){
			std::swap(input[i], input[r]);
			r++; i++; 
			}

		if(input[i]=='B'){
			std::swap(input[i], input[b]);
			b--; 
			}


		if(input[i]=='G'){
			i++;
			}

		}
	
	return input;

}


int main(){

	std::string input1 = "RGBGBGBRRBGRRBBGR", input2="GRBGRB", input3="", input4="RGBRGBRGBRGBRGBRGBRGBRGBRGB";
								
	std::string output = sort2(input4);

	std::cout << output << std::endl;

}
