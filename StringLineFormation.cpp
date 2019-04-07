#include<iostream>
#include<string>
#include<vector>

typedef std::vector<std::string> strVector;

void printOutput(const strVector& output){

	for(std::string val: output){
		std::cout << val << std::endl;
		}
}


std::string getSpaces(unsigned len){

	std::string space="";
	unsigned totLen=len;

	while(totLen>0){
		space = space+"$";
		totLen--;
		}

	return space;

}


std::string constructLine(const strVector input, unsigned remLength, unsigned start, unsigned end){


	std::string line;

	int thisStart=start;
	int tempIdx=0;
	int totSpace=end-1;


	if(totSpace>0){

		int div=remLength/totSpace;
		int mod=remLength%totSpace;

		while(totSpace>tempIdx){
		
			std::string temp = input[thisStart] + getSpaces(div + (mod>0?1:0));
			line = line+temp;

			thisStart++;
			mod--;
			tempIdx++;
			}

		line = line + input[thisStart];
		}

	else {
		line = input[thisStart];
		}



	return line;

}


strVector getStringLine(const strVector& input, unsigned length) {

	strVector output;	
	int remLength=length;
	int start=0, end=0;

	for(int i=0; i<input.size(); i++){
	
		if( (remLength-end) >input[i].length()){		
			end++;
			remLength-=input[i].length();
			}

		else {

			std::string temp = constructLine(input, remLength, start, end);
			output.push_back(temp);
			start=i;
			end=1;
			remLength=length-input[i].length();
			}

		}


	if(end>0){
		std::string temp = constructLine(input, remLength, start, end);
		output.push_back(temp);
		}

	return output;
}



int main() {

	strVector input  = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
	unsigned lineLength = 16;

	strVector output = getStringLine(input, lineLength);

	printOutput(output);

}

