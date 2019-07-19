#include<iostream>
#include<fstream>

void printFile(const std::string& fileName){

	std::ifstream file(fileName);

	std::string eachLine;

	while(std::getline(file, eachLine)){
		std::cout << eachLine << std::endl;
		}

	return;

}

int main(){

	printFile("/home/magizhini/Desktop/Daily Coding Problems/File Reading/FileReading.cpp	");

	return 0;
}
