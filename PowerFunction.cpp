#include<iostream>

unsigned helper(unsigned base, unsigned pow){

	if(pow==1){
		return base;
		}
	
	if(pow%2==0){
		return helper(base*base, pow/2);
		}

	else {
		return base * helper(base*base, pow/2);
		}

}

unsigned powerFunction(unsigned base, unsigned pow){

	if(pow==0){
		return 1;
		}

	else {
		return helper(base, pow);
		}
}

int main(){

	unsigned x=3, y=13;

	unsigned result = powerFunction(x, y);

	std::cout << "Pow(" << x << " , " << y << ") \t" << result << std::endl;

	return 0;
}
