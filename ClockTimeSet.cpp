#include<iostream>
#include<string>

unsigned calculateMin(const std::string& curSetTime, const std::string& tgtSetTime){

	unsigned total=0;

	unsigned h1 = std::stoi(curSetTime.substr(0,2));
	unsigned m1 = std::stoi(curSetTime.substr(3,2));
	unsigned h2 = std::stoi(tgtSetTime.substr(0,2));
	unsigned m2 = std::stoi(tgtSetTime.substr(3,2));

	unsigned min=0, t1=0, t2=0;

	//Hours Operation
	if(h1>h2){
		t1 = h1-h2;
		t2 = (23-h1) + 1 + h2;
		min = t1>t2 ? t2 : t1;
		}
	else if(h2>h1) {
		t1 = h2-h1;
		t2 = h1 + 1 + (23-h2);
		min = t1>t2 ? t2 : t1;
		}
	else {
		min=0;
		}

	total+=min;

	//Minute Operation
	if(m1>m2){
		t1 = m1-m2;
		t2 = (59-m1) + 1 + m2;
		min = t1>t2 ? t2 : t1;
		}
	else if(m2>m1) {
		t1 = m2-m1;
		t2 = m1 + 1 + (59-m2);
		min = t1>t2 ? t2 : t1;
		}
	else {
		min=0;
		}

	total+=min;

	return total;

}

int main(){

	std::string curSetTime = "08:12";
	std::string tgtSetTime = "23:27";

	unsigned minTask = calculateMin(curSetTime, tgtSetTime);

	std::cout << "Min Operation: " << minTask << std::endl;

	return 0;
}
