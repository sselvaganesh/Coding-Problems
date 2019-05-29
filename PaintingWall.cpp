#include<iostream>
#include<string>
#include<vector>

using namespace std;

static int count = 1;

void printval(const std::vector<std::string>& input){

	std::cout << "Stage: " << count << std::endl;

	for(auto str: input){
		std::cout  << str << " , ";

	}
	std::cout  << std::endl;

	count++;

}


bool allpainted(const std::vector<std::string>& input){

    std::string splChar = "@";

    for(auto eachStr: input){

        if(eachStr.find_first_not_of(splChar) < eachStr.length()){
                return false;
        }
    }

    return true;

}

bool rowPainted(const std::string& input) {

  std::string splChar = "@";

  if (input.find_first_not_of(splChar) < input.length()) {
    return false;
    }
    else{
      return true;
    }
 
}

void paint(std::string& input, int start, int len, char paintChar){
   
    char splChar = '@';

    for(int i=start; i<len; i++){

      if (input[i] == paintChar) {
        input[i] = splChar;
        }

    }


}


int strokesRequired(vector<string> picture) {

    int strokes = 0;

    for(int i=0; i<picture.size(); i++){

      if (rowPainted(picture[i])) {
        continue;
        }

        int len = 0;
        int pos = picture[i].find_first_not_of("@");
        int strPos = pos;
        char posChar = picture[i][strPos];

        while (true) {
		if(pos >= picture[i].length() || posChar != picture[i][pos]){
			break;
			}
            pos++;
            len++;
        }


        for(int j=0; j<picture.size(); j++){
          paint(picture[j], strPos, pos, posChar);
        }

	printval(picture);

        strokes++;
        
        if (!rowPainted(picture[i])) {
            i--;
        }


    }


    return strokes;

}

int main(){

	std::vector<std::string> input = {"aaababx", "ababac", "aaacad"};

	int output = strokesRequired(input);

	std::cout << output << std::endl;

	return 0;
}

