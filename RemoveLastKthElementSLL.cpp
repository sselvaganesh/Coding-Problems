#include<iostream>


typedef struct nodeTemplate{

	int data;
	nodeTemplate* next;

}* node;


node createNode(int val){

	node newNode = new nodeTemplate;
	newNode->data = val;
	newNode->next = NULL;

	return newNode;

}


node getLastNode(node root){

	if(root->next == NULL){
		return root;
		}
	else {
		getLastNode(root->next);
		}


}


void insertNode(node& root, int val){

	node tempNode = createNode(val);


	if(root==NULL){
		root=tempNode;
		return;
		}

	node curLastNode = getLastNode(root);
	curLastNode->next = tempNode;
	
	return;

}


void traverse(node root){

	while(root!=NULL){
		std::cout << root->data << "  ";
		root=root->next;
		}	

	std::cout << std::endl;

}


void deleteK(node& root, int k){

	int kPrev = k+1, i=0;
	node prevNode = NULL, tempRoot=root;


	while(tempRoot!=NULL){

		i++;

		if(prevNode!=NULL){
			prevNode=prevNode->next;
			}

		if(i==kPrev){
			prevNode=root;
			}

		tempRoot=tempRoot->next;

		}

	node tempNode;

	if(prevNode==NULL){
		//Root needs to be deleted
		
		tempNode = root;
		delete tempNode;
		
		root=root->next;		

		std::cout << "Root deleted" << std::endl;

		}
	else if(prevNode->next->next == NULL) {

		delete prevNode->next;
		prevNode->next = NULL;
		
		std::cout << "Tail element deleted.!" << std::endl;

		}

	else {
		std::cout << "Node: " << prevNode->next->data << " deleted successfully.!" << std::endl;

		tempNode = prevNode->next->next;	
		delete prevNode->next;
		prevNode->next = tempNode;
		}

}



void menu(){

	std::cout << "1. Insert Element" << std::endl;
	std::cout << "2. Insert N Elements" << std::endl;
	std::cout << "3. Print Nodes" << std::endl;
	std::cout << "4. Delete Kth Element From Last" << std::endl;	
	std::cout << "5. Exit" << std::endl;

}

void process(){

	node root = NULL;
	int val, n, k;

	char opt;


	while(opt!='5'){

		menu();

		std::cout << "Enter Option: ";
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout << "Enter Value: " ;
				std::cin >> val;
				insertNode(root, val);
				break;

			case '2':
				std::cout << "Enter No of Elements to be added: "; 
				std::cin >> n;				
				for(int i=0; i<n; i++){
					insertNode(root, i*3);
					}		
				break;

			case '3':
				traverse(root);
				break;

			case '4':
				std::cout << "Enter Kth Element from Last: ";
				std::cin >> k;
				deleteK(root, k); 
				break;

			case '5':
				break;

			default:
				std::cout << "Invalid option." << std::endl;
				break;

				}


		}


}


int main(){

	process();	


}
