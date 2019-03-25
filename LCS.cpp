#include<iostream>
#include<string>
#include<unordered_map>

typedef std::unordered_map<std::string, std::string> lcsMapTemplate;

std::string max(std::string i, std::string j){	
	return (i.length()>j.length()?i:j);
}

std::string helper(std::string s1, std::string s2, int l1, int l2, int pos1, int pos2, lcsMapTemplate& lcsMap){


	//base case
	if(l1==0 || l2==0){
		return "";
		}

	if(s1[pos1]=='\0' || s2[pos2]=='\0'){
		return "";
		}

	std::string key = std::to_string(pos1) + std::to_string(pos2);
	
	if(lcsMap.find(key)==lcsMap.end()){
	
		if(s1[pos1]==s2[pos2]){		
			lcsMap[key] = s1[pos1]+helper(s1, s2, l1, l2, pos1+1, pos2+1, lcsMap);
			}
		else {
			lcsMap[key] = max(helper(s1, s2, l1, l2, pos1+1, pos2, lcsMap), helper(s1, s2, l1, l2, pos1, pos2+1, lcsMap));
			}
	
		}

	return lcsMap[key]; 

}

std::string lcs(std::string str1, std::string str2){

	int l1=str1.length();
	int l2=str2.length();

	lcsMapTemplate lcsMap; 

	return helper(str1, str2, l1, l2, 0, 0, lcsMap);

}


int main(){

	std::string str1="ABCBDAB", str2="BDCABA";

	std::string lcsLength=lcs(str1, str2);

	std::cout << "LCS Length: " << lcsLength <<std::endl;

	return 0;
}



