#include<iostream>
#include<string>

unsigned min(unsigned i, unsigned j, unsigned k){

	return (i<j&&i<k?i:j<k?j:k);

}

unsigned helper(std::string s1, std::string s2, unsigned l1, unsigned l2){

	//If target string is empty
	if(l2==0){
		return l1;
		}

	//If base string is empty
	else if(l1==0){
		return l2;
		}

	//Last character is matched in both the strings
	if(s1[l1-1]==s2[l2-1]){
		return helper(s1, s2, l1-1, l2-1);
		}

	return 1+ min(	helper(s1, s2, l1, l2-1), 	//Append last character with the base string and check//
			helper(s1, s2, l1-1, l2),	//Delete last character from the base string and check//
			helper(s1, s2, l1-1, l2-1)	//Replace last character with the base string and check//
			);


}

unsigned getEditDistance(std::string s1, std::string s2){

	return helper(s1, s2, s1.length(), s2.length());

}


int main(){

	std::string s1="kitten", s2="sitting";

	unsigned editDistance = getEditDistance(s1, s2);

	std::cout << "Edit Distance: " << editDistance << std::endl;

}
