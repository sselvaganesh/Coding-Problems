#include<iostream>
#include<string>

void reverseLine(std::string& line){

	for(int i=0, j=line.length()-1; j>i; i++, j--){
		std::swap(line[i], line[j]);
		}

}

void reverseWords(std::string& line){

	int start = 0;
	int end = line.find(" ", 0);

	while(end!=std::string::npos){
		
		for(int i=start, j=end-1; j>i; i++, j--){
			std::swap(line[i], line[j]);
			}

		start=end+1;
		end=line.find(" ", start);
		}

	for(int i=start, j=line.length()-1; j>i; i++, j--){
		std::swap(line[i], line[j]);
		}
	
}

std::string reverse(const std::string& input){

	if(input==""){
		return " ";
		}

	std::string output = input;

	reverseLine(output);

	reverseWords(output);

	return output;

}


int main(){

	std::string input = "Ganesh Selva";

	std::string output = reverse(input);

	std::cout << input << std::endl << output << std::endl;

}
