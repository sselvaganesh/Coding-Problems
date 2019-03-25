#include<iostream>

typedef struct nodeTemplate{
	int data;
	nodeTemplate* addr;
}* node;


node createNode(int val){

	node temp = new nodeTemplate;
	temp->data = val;
	temp->addr = NULL;

	return temp;
}

node calcXOR(uintptr_t node1, uintptr_t node2){
	return  (node) (node1 ^ node2);
}

node insertNode(node& root, int val){

	node prev=NULL, cur=NULL, next=NULL;
	node newNode = createNode(val);

	if(root==NULL){
		root=newNode;
		root->addr = calcXOR((uintptr_t)(prev), (uintptr_t)(next));
		}

	else {
		cur=root;
		node temp;
		while(calcXOR( (uintptr_t)(prev), (uintptr_t)(cur->addr) ) != NULL){
			temp=cur;
			cur = calcXOR((uintptr_t)(prev), (uintptr_t)(cur->addr));
			prev = temp;			
			}

		cur->addr = calcXOR((uintptr_t)(prev), (uintptr_t)(newNode));	
		prev=cur;	
		newNode->addr = calcXOR((uintptr_t)(prev), (uintptr_t)(next));
		}

	return newNode;

}

void traverse(node root){

	node prev=NULL, cur=NULL, next=NULL;

	if(root==NULL){
		std::cout << "XOR List is Empty.!" << std::endl;
		return;
		}	
	else {
		cur=root;	
		while(cur != NULL){
			std::cout << cur->data << '\t';
			next = calcXOR((uintptr_t)(prev), (uintptr_t)(cur->addr));
			prev=cur;
			cur=next;
			}

		}

	std::cout <<std::endl;
}


void deleteNode(node& root, node& tail, int delVal){
	
	//List is Empty
	if(root==NULL){
		std::cout << "List is empty.!" << std::endl;
		return;
		}

	node prev=NULL, cur=root, next=NULL, prev2=NULL, next2=NULL;
	
	//Root has deletion element, no further element
	if(root->data==delVal && root==tail){
		delete root;
		root=NULL; tail=NULL;
		return;
		}

	//Other elements
	while( calcXOR((uintptr_t)(prev), (uintptr_t)(cur->addr)) != NULL ){

		if(cur->data==delVal){
			break;
			}

		next = calcXOR((uintptr_t)(prev), (uintptr_t)(cur->addr));
		prev = cur;
		cur = next;
		}

	next = calcXOR((uintptr_t)(prev), (uintptr_t)(cur->addr));

	//Delete element not found
	if(cur->data != delVal){
		std::cout << "Element not found.!" << std::endl;
		return;
		}

	//Element found for deletion
	if(prev !=NULL){
		prev2 = calcXOR((uintptr_t)(cur), (uintptr_t)(prev->addr));
		}

	if(next !=NULL){
		next2 = calcXOR((uintptr_t)(cur), (uintptr_t)(next->addr));
		}


	if(prev != NULL){
		prev->addr = calcXOR((uintptr_t)(prev2), (uintptr_t)(next));
		}

	if(next !=NULL){
		next->addr = calcXOR((uintptr_t)(prev), (uintptr_t)(next2));
		}

	if(cur==root){
		root=next;
		}

	if(cur==tail){
		tail=prev;
		}

	std::cout << cur->data << " - Element deleted successfully.!"  << std::endl;
	delete cur;	

}

void printMenu(){
	std::cout << "1. Insert node" << std::endl;
	std::cout << "2. Delete node" << std::endl;
	std::cout << "3. Print Forward" << std::endl;
	std::cout << "4. Print Reverse" << std::endl;
	std::cout << "5. Load 10 Values" << std::endl;
	std::cout << "6. Exit" << std::endl;

	std::cout << "Enter Option: ";

}


int main(){

	node root=NULL, last=NULL;
	char opt;
	int val;

	while(opt != '6'){

		printMenu();	
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout <<"Enter value: ";
				std::cin >> val;
				last=insertNode(root, val);				
				break;

			case '2':
				std::cout <<"Enter value: ";
				std::cin >> val;
				deleteNode(root, last, val);
				break;

			case '3':
				traverse(root);
				break;

			case '4':
				traverse(last);
				break;

			case '5':
				for(int i=1; i<=10; i++){
					last=insertNode(root, i*10);
					}
					std::cout << "Value inserted (10, 20, 30 ... 100)...!!! " << std::endl;

				break;				

			case '6':
				break;			

			default:
				std::cout << "Invalid Option.!" << std::endl;
				break;
			}

		}

	return 0;
}

