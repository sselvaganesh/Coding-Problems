#include<iostream>
#include<vector>
#include<deque>

typedef std::vector<int> oneDimVec;
typedef std::deque<int> myDeque;

void usingDeque(const oneDimVec& input, int k){

	if(input.size()==0){
		return;
		}


	std::cout << "Deque:      \t";

	myDeque tempDeque;
	int front, back;
	

	for(int i=0; i<k; i++){

		if(tempDeque.empty()){
			tempDeque.push_back(i);
			}
		else {

			while(!tempDeque.empty() && input[i] > input[tempDeque.back()]){
				tempDeque.pop_back();
				}
			tempDeque.push_back(i);
			}	

		}


	for(int i=k; i<input.size(); i++){

		std::cout << input[tempDeque.front()] << '\t';

		while(!tempDeque.empty() && tempDeque.front() <= (i-k)){
			tempDeque.pop_front();
			}
		
		while(!tempDeque.empty() && input[i] > input[tempDeque.back()]){
			tempDeque.pop_back();
			}
		tempDeque.push_back(i);

		}
	
	std::cout << input[tempDeque.front()] << '\t';

	std::cout <<std::endl;
	
}



void bruteForce(const oneDimVec& input, int k){

	if(input.size()==0){
		return;
		}


	std::cout << "Brute Force: \t";

	for(int i=0; i<input.size()-k+1; i++){

		int max = input[i];

		for(int j=i+1, temp=1; temp<k; j++, temp++){
			
			if(input[j]>max){
				max=input[j];
				}

			}

		std::cout << max << '\t';

		}

	std::cout << std::endl;

}


int main(){

	oneDimVec input = {10, 5, 2, 7, 8, 7};	
	int k=3;

	bruteForce(input, k);
	usingDeque(input, k);

}
