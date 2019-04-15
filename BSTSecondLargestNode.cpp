#include<iostream>

typedef struct nodeTemplate{

	nodeTemplate* left;
	int data;
	nodeTemplate* right;

}* node;

node createNode(int val){

	node newNode = new nodeTemplate;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = val;

	return newNode;
}


node getParent(node root, int val){


	if(root->data>val){
		
		if(root->left==NULL){
			return root;
			}
		else {		
			return getParent(root->left, val);
			}
		}	

	else {

		if(root->right==NULL){
			return root;
			}
		else {
			return getParent(root->right, val);

			}
		}


}

void insertNode(node &root, int val){

	node newNode = createNode(val);

	if(root==NULL){
		root=newNode;			
		}

	else {

		node parent = getParent(root, val);
		
		if(parent->data>val){
			parent->left = newNode;
			}
		else {
			parent->right = newNode;
			}

		}

	std::cout << "Node inserted successfully..!!!" << std::endl;

}

void inOrder(node root){

	if(root==NULL){
		return;
		}

	std::cout << root->data << '\t';
	inOrder(root->left);
	inOrder(root->right);
	
}


void preOrder(node root){

	if(root==NULL){
		return;
		}


	preOrder(root->left);
	std::cout << root->data << '\t';
	preOrder(root->right);

}

void postOrder(node root){

	if(root==NULL){
		return;
		}

	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->data << '\t';
}

void traverse(node root){

	std::cout << "In-Order Traversal" << std::endl;
	inOrder(root);
	std::cout << std::endl;

	std::cout << "Pre-Order Traversal" << std::endl;
	preOrder(root);
	std::cout << std::endl;

	std::cout << "Post-Order Traversal" << std::endl;
	postOrder(root);
	std::cout << std::endl;

}


node getLargestNodeParent(node root, node parent){

	if(root->right==NULL){
		return parent;
		}	
	else {
		getLargestNodeParent(root->right, root);
		}

}


void getSecondLargest(node root){

	if(root==NULL){
		std::cout << "BST is empty.!!!" << std::endl;
		return;
		}
	
	node parent = getLargestNodeParent(root, root);

	if(parent->left==NULL && parent->right==NULL){
		std::cout << "BST has only one element.!" << std::endl;
		return;
		}

	if(parent->right==NULL){
		std::cout << "Second Largest: " << parent->left->data << std::endl;
		}

	else {
		std::cout << "Second Largest: " << parent->data << std::endl;
		}


}



void dsplyMenu(){

	std::cout << "1. Insert Node" << std::endl;
	std::cout << "2. Traversal" << std::endl;
	std::cout << "3. Retrieve Second Largest" << std::endl;
	std::cout << "4. Insert 10 elements" << std::endl;
	std::cout << "5. Exit" << std::endl;
}


void process(){

	node root=NULL;
	char opt;
	int val;
	

	while(opt!='5'){

		dsplyMenu();
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout << "Enter value: ";
				std::cin>>val;
				insertNode(root, val);
				break;

			case '2':
				traverse(root);
				break;

			case '3':
				getSecondLargest(root);
				break;			

			case '4':
				for(int i=1; i<=10; i++){
					insertNode(root, i*10);
					}
				break;


			case '5':
				break;				

			default:		
				std::cout << "Invalid Option.!"<< std::endl;
				break;
				}

		}


}


int main(){

	process();

}
