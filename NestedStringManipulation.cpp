#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> splitStr(std::string inpStr, std::vector<std::string> strVector){

	std::vector<std::string> vecOutput;

	int start = 0;
	int pos = inpStr.find("|", start);
	int len = inpStr.length();
	const std::string marker = "$";
	int totStr = strVector.size();

	while(pos>0){
		
		if(totStr==0){
			vecOutput.push_back(inpStr.substr(start, pos-start));
			}

		else {

			for(int i=0; i<totStr; i++){
				vecOutput.push_back(strVector[i] + marker + inpStr.substr(start, pos-start));
				}

			}
		
		start=pos+1;
		pos = inpStr.find("|", start);
		}


	if(totStr==0){
		vecOutput.push_back(inpStr.substr(start, len-start));
		}

	else {

		for(int i=0; i<totStr; i++){
			vecOutput.push_back(strVector[i] + marker + inpStr.substr(start, len-start));
			}

		}

	return vecOutput;

}


void printStringComb(std::string input){

	if(input.length()==0){
		return;
		}


	std::string copyInp = input;
	std::vector<std::string> strVector, strOutput;
	

	copyInp.replace(0, 1, "");
	copyInp.replace(copyInp.length()-1, 1, "");

	int start=copyInp.find("{", 0);
	int end;

	if(start < 0){
		std::cout << copyInp << std::endl;
		return;
		}

	const std::string strMarker = "<>";
	const std::string vecMarker = "$";

	while(start > 0){
		end = copyInp.find("}", start+1);

		std::string temp = copyInp.substr(start+1, end-start-1);
		copyInp.replace(start, end-start+1, strMarker);
		
		strOutput = splitStr(temp, strVector);
		strVector.erase(strVector.begin(), strVector.end());
		strVector.assign(strOutput.begin(), strOutput.end());

		start=copyInp.find("{", 0);

		}

/*	std::cout << copyInp << std::endl;

	for(std::string &val: strOutput){
		std::cout << val << std::endl;

		}

*/	
	for(std::string &val: strOutput){

		std::string tempOutput = copyInp;

		int vecStart = 0;	
		int vecEnd = val.find(vecMarker, vecStart);

		int strStart = copyInp.find(strMarker, 0);

		while(strStart > 0){

			tempOutput.replace(strStart, 2, val.substr(vecStart, vecEnd-vecStart));

			vecStart = vecEnd+1;
			vecEnd=val.find(vecMarker, vecStart);

			strStart = tempOutput.find(strMarker, 0);
			}

		std::cout << tempOutput << std::endl;
		}


}

int main(){

	std::string input = "{ this is a {super|good|nice} place to {visit|live} }";	//Test case 1 -- Pass
	//std::string input = "{ }";							//Test case 2 -- Pass
	//std::string input = "{ this is a {super}  place to {live} }";			//Test case 3 -- Pass
	//std::string input = "{ this is a {super|good|nice} place to visit }";		//Test case 4 -- Pass
	//std::string input = "{ this is a super place to visit }";			//Test case 5 -- Pass
	//std::string input = "{ {super|good|nice} {visit|live} {pass|fail} }";		//Test case 6 -- Pass

	printStringComb(input);

	return 0;
}

