#include<iostream>
#include<vector>

typedef std::vector<int> oneDimVec;

int calculate(int remSteps, oneDimVec& steps){

	if(remSteps==0){
		return 1;
		}

	int result=0, i=0;

	while(i<steps.size()){

		if(remSteps >= steps[i]){
			result+=calculate(remSteps-steps[i], steps);
			}
		i++;
	}

	return result;
}

int main(){

	oneDimVec stepsArr = {2, 1};

	int n=5;	

	int output = calculate(n, stepsArr);

	std::cout << "Possible Ways: " << output << std::endl;

	return 0;
}
