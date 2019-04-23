#include<iostream>
#include<limits.h>



typedef struct nodeTemplate {

	static int max;
	int data;
	nodeTemplate* prev;
	
}* node;

int nodeTemplate::max = INT_MIN;

void push(int val, node& curTop){

	node newNode = new nodeTemplate;
	newNode->data = val;
	newNode->prev = curTop;

	curTop = newNode;
	
	if(val > nodeTemplate::max){
		nodeTemplate::max = val;
		}

}

void pop(node& curTop){

	if(curTop!=NULL){
		node temp = curTop->prev;
		delete curTop;
		curTop = temp;
		}
	else {
		std::cout << "*** Stack is empty.! *** " << std::endl;
		}

}

void getTop(node& curTop){

	if(curTop!=NULL){
		std::cout << "Top: "<< curTop->data << std::endl;
		}	
	else {
		std::cout << "*** Stack is empty.! *** " << std::endl;
		}

}

void printStack(node& curTop){

	if(curTop==NULL){
		std::cout << " *** Stack is empty.! *** " << std::endl; 
		return;
		}

	node curNode = curTop;

	while(curNode!=NULL){
		std::cout << curNode->data << '\t';
		curNode = curNode->prev;
		}

	std::cout << std::endl;

}

void menu(){

	std::cout << "1. Push" << std::endl;
	std::cout << "2. Pop" << std::endl;
	std::cout << "3. Top" << std::endl;
	std::cout << "4. Max" << std::endl;
	std::cout << "5. Print Stack" << std::endl;
	std::cout << "6. Exit" << std::endl;
	std::cout << "Enter option: " ;

}

void process(){

	char opt;
	node top=NULL;


	while(opt!='6'){

		menu();
		std::cin >> opt;

		switch(opt){


			case '1':		
				int val;
				std::cout << "Enter value: ";
				std::cin >> val;
				push(val, top);
				break;

			case '2':
				pop(top);
				break;

			case '3':
				getTop(top);		
				break;

			case '4':
				if(top!=NULL){
					std::cout << "Max: " << nodeTemplate::max << std::endl;
					}
				else {
					std::cout << "*** Stack is Empty *** " << std::endl;
					}

				break;


			case '5':
				printStack(top);
				break;


			case '6':		
				break;


			default:
				std::cout << "Invalid option.!" << std::endl;
				break;

			}

		}


}


int main(){

	process();

}
