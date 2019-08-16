#include<iostream>
#include<map>
#include<vector>

std::vector<int> subarraySort(std::vector<int> array) {

	int max = array[0];

	std::vector<int> output={-1, -1};

	std::map<int, int> elemIdxPos;
	
	elemIdxPos[array[0]] = 0;
	
	for(int i=1; i<array.size(); i++){
						
		if(array[i]>=max){
				max=array[i];
			}
		else {
			output[1] = i;

			auto itr=elemIdxPos.upper_bound(array[i]);
			
			if(output[0]==-1 || output[0] > (*itr).second){
				output[0] = (*itr).second;			
				}
		
		} 		

		if(elemIdxPos.find(array[i])==elemIdxPos.end()){
			elemIdxPos[array[i]] = i;
			}
		
		
	}	
	
	return output;
	
}


int main(){


	//std::vector<int> input = {1, 2};	//-1, -1
	//std::vector<int> input = {2, 1};	//0, 1
	std::vector<int> input = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};	//3,9
	//std::vector<int> input = {1, 2, 4, 7, 10, 11, 7, 12, 7, 7, 16, 18, 19};	//4,9

	std::vector<int> output = subarraySort(input);

	std::cout << output[0] << '\t' << output[1]<< std::endl;

	return 0;
}
