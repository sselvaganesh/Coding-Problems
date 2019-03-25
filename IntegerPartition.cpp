#include<iostream>
#include<vector>

int count=0;

void printVector(std::vector<int> inpVector){

	for(int &val: inpVector){

		if(val>0){		
			std::cout << val << '\t';
			}
		}

	std::cout << std::endl;

}


void printPartition(std::vector<int> inpVector, int pos) {

	count++;

	if(inpVector[0] >= inpVector[1]){
			printVector(inpVector);
			}


	while(inpVector[pos]>1){
		
			inpVector.at(pos) = inpVector[pos]-1;		
			auto itr = inpVector.begin()+pos+1;
			inpVector.insert(itr,1);
			
			printPartition(inpVector, pos+1);
			}


}


void intPartition(int input){

	for(int i=0; i<input; i++){

		std::vector<int> inpVector;
		
		inpVector.push_back(input-i);
		inpVector.push_back(input- (input-i));
		
		printPartition(inpVector, 1);

		}

}


int main(){

	intPartition(5);

	std::cout << "Time complexity: " << count << std::endl;

	return 0;
}
