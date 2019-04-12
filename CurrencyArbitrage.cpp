#include<iostream>
#include<vector>

int count=0;

typedef std::vector<float> oneDimIntVec;
typedef std::vector<std::vector<float>> twoDimIntVec;

bool convertCurr(const twoDimIntVec& currExcTbl, unsigned inpCurr, unsigned inpAmt, unsigned currCurr, unsigned curExcAmt){

	float excFnlVal = (currExcTbl[currCurr][inpCurr] * curExcAmt);

	if( excFnlVal > inpAmt){
		return true;
		}

	else {
		return false;
		}
		
}


bool helper(const twoDimIntVec& currExcTbl, oneDimIntVec remCurr, unsigned inpAmt, unsigned inpCurr, unsigned currCurr, unsigned excAmt){

	if(remCurr.size()==0){
		return false;
		}


	count++;

	float curExcAmt = 0;
	auto itr = remCurr.begin();
	std::string tempStr;
	unsigned next;

	for(int i=0; i<remCurr.size(); i++){

		next = remCurr[i];
		curExcAmt = currExcTbl[currCurr][next] * excAmt;
		itr+=i;
		remCurr.erase(itr);

		bool isExcAmtGreater = helper(currExcTbl, remCurr, inpAmt, inpCurr, next, curExcAmt);

		if(isExcAmtGreater){
			return true;
			}

		remCurr.insert(itr, next);
		}	

	return convertCurr(currExcTbl, inpCurr, inpAmt, next, curExcAmt);
	
}


bool determineArbitrage(const twoDimIntVec& currExcTbl, unsigned inpAmt, unsigned inpCurr){

	oneDimIntVec remCurr;

	//Make a list of remaining currencies
	for(int i=0; i<currExcTbl.size(); i++){

		if(i!=inpCurr){
			remCurr.push_back(i);
			}

		}


	return helper(currExcTbl, remCurr, inpAmt, inpCurr, inpCurr, inpAmt);

}


int main(){

/*
	twoDimIntVec currExcTbl = {
					{1,  0.25,    0.2},	//USD		//Returns TRUE
					{4,     1,   1.25},	//CAD
					{5,  0.80,    1}	//EUR
					};
	unsigned inpAmt = 500;

*/
	twoDimIntVec currExcTbl = {
					{1, 2, 0.5},		//USD
					{0.5, 1, 0.25},		//CAD		//Returns FALSE
					{2, 4, 1}		//EUR
					};
	unsigned inpAmt = 5;


	unsigned inpCurr = 0;		//USD

	bool arbitrage = determineArbitrage(currExcTbl, inpAmt, inpCurr);

	std::cout << std::boolalpha << "Arbitrage: " << arbitrage << std::endl;

}



