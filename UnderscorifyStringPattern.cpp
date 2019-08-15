#include<iostream>
#include<string>

int max(int val1, int val2){

	return val1>val2 ? val1 : val2;

}

int locateSubstring(const std::string& input, const std::string& pattern, int startPos, int output){

	int overLapPos=-1, start=startPos;
	
	if(startPos>=input.length()){
		return output;
		}

	
	for(int i=0; start<input.length() && i<pattern.length(); i++, start++){
		
		if(pattern[i]!=input[start]){
			return output;			
			}
		
		if(i>0 && pattern[0]==input[start] ){
			overLapPos=start;
			}
		
		}

	output=start;
	
	return max (locateSubstring(input, pattern, start, output) , locateSubstring(input, pattern, overLapPos, output) );
		
}

std::string underscorifySubstring(const std::string& str, const std::string& subStr) {
	
	std::string output = str;
	int subStrPos=-1;
	
	for(int i=0; i<output.length(); i++){

		if(output[i]==subStr[0]){		
			subStrPos=-1;
			subStrPos = locateSubstring(output, subStr, i, subStrPos);
			
			if(subStrPos!=-1){
				output.insert(subStrPos, "_");
				output.insert(i, "_");
				i=subStrPos;
				}			
			
			}	
		
		}
	
	return output;
}

int main(){

	//std::string input="this is a test to see if it works", pattern="test";			//1	this is a _test_ to see if it works
	//std::string input="test this is a test to see if it works", pattern="test";			//2	_test_ this is a _test_ to see if it works
	//std::string input="testthis is a test to see if it works", pattern="test";			//3	_test_this is a _test_ to see if it works
	//std::string input="testthis is a testest to see if testestes it works", pattern="test";	//4	_test_this is a _testest_ to see if _testest_es it works
	//std::string input="testthis is a testtest to see if testestest it works", pattern="test";	//5	_test_this is a _testtest_ to see if _testestest_ it works
	//std::string input="this is a test to see if it works and test", pattern="test";		//6	this is a _test_ to see if it works and _test_
	//std::string input="this is a test to see if it works and test", pattern="bfjawkfja";		//7	this is a test to see if it works and test
	//std::string input="ttttttttttttttbtttttctatawtatttttastvb", pattern="ttt";			//8	_tttttttttttttt_b_ttttt_ctatawta_ttttt_astvb
	//std::string input="tzttztttz", pattern="ttt";							//9	tzttz_ttt_z
	std::string input="abababababababababababababaababaaabbababaa", pattern="a";			//10	_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_aa_b_a_b_aaa_bb_a_b_a_b_aa_
	//std::string input="abcabcabcabcabcabcabcabcabcabcabcabcabcabc", pattern="abc";		//11	_abcabcabcabcabcabcabcabcabcabcabcabcabcabc_


	std::string output = underscorifySubstring(input, pattern);

	std::cout << input << std::endl << output << std::endl;

	return 0;
}


