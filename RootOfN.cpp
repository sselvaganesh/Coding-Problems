#include<iostream>

float root(const float& input){

	if(input<=1){
		return input;
		}

	float output=input/2, tempVal=input/2;
	
	while(true){

		if( (output*output)-input > -0.0001 && (output*output)-input < 0.0001){
			break;
			}

		else if((output*output) > input ){
			output-= (tempVal/2);
			}
		else {
			output+= (tempVal/2);
			}

		tempVal/=2;		
	
		}	
	

	return output;
}


int main(){

	float input1 = 4, input2=5, input3=2;

	float output = root(input3);

	std::cout << input3 << '\t' << output << std::endl;

	return 0;
}
