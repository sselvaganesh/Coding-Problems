#include<iostream>

typedef struct nodeTemplate{

	bool locked;
	int data;
	nodeTemplate* left;
	nodeTemplate* right;

}* node;

node createNode(int val){

	node temp = new nodeTemplate;

	temp->locked = false;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void inorderTraverse(node root){

	if(root==NULL){
		return;
		}

	std::cout << root->data << '\t';
	inorderTraverse(root->left);		
	inorderTraverse(root->right);

}


node getNode(node root, int val){
	
	if(root->data >= val && root->left != NULL){
		return getNode(root->left, val);
		}
	else if(root->data < val && root->right !=NULL){
		return getNode(root->right, val);
		}
	else {
		return root;
		}
	
}


void insertNode(node &root, int val){

	node newNode = createNode(val);

	if(root==NULL){
		root=newNode;
		return;
		}

	node parentNode = getNode(root, val);	

	if(parentNode->data >= val){
		parentNode->left = newNode;
		}
	else {
		parentNode->right = newNode;
		}

	std::cout << "Node inserted successfully.!" << std::endl;

}


void isLocked(node root, int val){

	while(root!=NULL){
	
		if(root->data==val){
			break;
			}
		else if(root->data >= val){
			root=root->left;
			}
		else {
			root=root->right;
			}

		}

	if(root==NULL || root->data != val){
		std::cout << "Node not found with value " << val << std::endl;
		return;
		}

	std::cout << std::boolalpha << "Node Locked.? : " << root->locked << std::endl;


}

void getNodes(node &parent, node& current, node root, int val){

	if(root==NULL){
		return;
		}

	else if(root->data == val){
		current = root;
		return;
		}

	parent = root;

	if(root->data >= val){
		current = root->left;
		getNodes(parent, current, current, val);
		}
	else {
		current = root->right;
		getNodes(parent, current, current, val);
		}	

}


void lockUnlock(node root, node parent, int val, bool lock){

	node nodeParent=NULL, nodeCurrent=NULL;

	getNodes(nodeParent, nodeCurrent, root, val);	

	if(nodeCurrent== NULL){
		std::cout << " 1. Node not found.!" << std::endl;
		return;
		}
	else if(nodeCurrent->data != val){
		std::cout << "2. Node not found.!" << std::endl;
		return;
		}

	if( (nodeParent == NULL || (nodeParent !=NULL && nodeParent->locked==false) )&& 
		nodeCurrent->locked == false && 
		( nodeCurrent->left == NULL  || (nodeCurrent->left != NULL && nodeCurrent->left->locked == false) ) &&
		( nodeCurrent->right == NULL || (nodeCurrent->right != NULL && nodeCurrent->right->locked == false ) ) 
		)
			{



		if(lock){
			nodeCurrent->locked = true;
			std::cout << "Node locked successfully.!"<< std::endl;
			}
		else{
			nodeCurrent->locked = false;
			std::cout << "Node Un-locked successfully.!"<< std::endl;
			}


		}
	else {
		std::cout << "Can not lock node.! :-("<< std::endl;
		}

}



void menu(){

	std::cout << "1. Add Node" << std::endl;
	std::cout << "2. Traverse (In-Order)" << std::endl;
	std::cout << "3. Is Node Locked.?" << std::endl;
	std::cout << "4. Lock Node" << std::endl;
	std::cout << "5. Unlock Node" << std::endl;
	std::cout << "6. Exit" << std::endl;
}



void showMenu(){

	char opt;
	node root=NULL, parent=NULL;
	int val;

	while(opt!=6){

		menu();
		std::cout << "Enter option: ";
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout << "Enter node value: ";
				std::cin >> val;				
				insertNode(root, val);
				break;

			case '2':
				inorderTraverse(root);
				std::cout << std::endl;
				break;

			case '3':
				std::cout << "Enter node value: ";
				std::cin >> val;	
				isLocked(root, val);
				break;

			case '4':
				std::cout << "Enter node value: ";
				std::cin >> val;	
				lockUnlock(root, NULL, val, 1);
				break;

			case '5':
				std::cout << "Enter node value: ";
				std::cin >> val;	
				lockUnlock(root, NULL, val, 0);
				break;

			case '6':
				return;

			default:
				std::cout << "*** Invalid option.! " << std::endl;
				break;

				}


		}


}


int main(){

	showMenu();

}
