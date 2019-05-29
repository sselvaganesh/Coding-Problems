#include<iostream>
#include<time.h>
#include<stdlib.h>

typedef struct nodeTemplate{

	nodeTemplate* left;
	nodeTemplate* right;
	int data;

}* node;



node createNode(int val){

	node temp = new nodeTemplate;

	temp->left = NULL;
	temp->right = NULL;
	temp->data = val;

	return temp;

}


node getParent(node root, int val){

	if(root->data > val){

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

		else{

			return getParent(root->right, val);
			}

		}


}


void traverse(node root){

	if(root==NULL){
		return;
		}


	std::cout << root->data << '\t';
	traverse(root->left);
	traverse(root->right);

}



void insertNode(node& root, int val){

	node newNode = createNode(val);


	if(root==NULL){
		root = newNode;		
		}
	else {

		node parent = getParent(root, val);

		if(parent->data > val){
			parent->left = newNode;
			}

		else {
			parent->right = newNode;
			}

		}


	std::cout << "Node inserted successfully.!" << std::endl;

}


void getDeepestNode(node root, int depth, int val){

	static int gblDepth=0, gblVal;

	if(root==NULL){

		if(depth==0){
			std::cout << "BST is empty.!"<< std::endl;
			}
		return;
		}

	 if(root->left==NULL && root->right==NULL && gblDepth<=depth){
			gblDepth=depth;
			gblVal = root->data;
		}

	getDeepestNode(root->left, depth+1, val);
	getDeepestNode(root->right, depth+1, val);

	if(depth==0){
		std::cout << "Highest depth: " << gblDepth << "\t Value: " << gblVal << std::endl;
		}

}

void dsplyMenu(){

	std::cout << "1. Insert Node" << std::endl;
	std::cout << "2. Traverse" << std::endl;
	std::cout << "3. Get Deepest Node" << std::endl;
	std::cout << "4. Insert 10 Random Nodes (<=50)" << std::endl;
	std::cout << "5. Exit" << std::endl;
	std::cout << "Enter option: ";

}


void process(){

	node root=NULL;
	int val; char opt;

	srand(time(NULL));


	while(true){

		dsplyMenu();
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout << "Enter Value: ";
				std::cin >> val;
				insertNode(root, val);	
				break;

			case '2':
				traverse(root);
				std::cout << std::endl;
				break;

			case '3':
				getDeepestNode(root, 0, 0);
				break;

			case '4':

				for(int i=0; i<10; i++){
					insertNode(root, rand()%50+1);
					}				
				break;
				

			case '5':
				return;

			default:
				std::cout << "Invalid option.!" << std::endl;
				break;

			}


		}


}


int main(){

	process();

	return 0;
}
