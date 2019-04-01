#include<iostream>

typedef struct nodeTemplate{

	int data;
	nodeTemplate* next;
}* node;

void traverse(node root){

	while(root!=NULL){
		std::cout << root->data << '\t';
		root=root->next;
		}

	std::cout << std::endl;
}

node createNode(int val){

	node temp = new nodeTemplate;
	temp->data=val;
	return temp;
}


node getLastNode(node root){

	while(root->next!=NULL){
		root=root->next;
		}

	return root;
}


void insertNode(node& root, int val){

	node newNode = createNode(val);

	if(root==NULL){
		root=newNode;
		return;
		}
	else {
		node lastNode = getLastNode(root);
		lastNode->next = newNode;
		}

	std::cout << "Node Inserted.!" << std::endl;
}


void dslpyMenu(){

	std::cout << "1. Insert node to List1" << std::endl;
	std::cout << "2. Insert node to List2" << std::endl;
	std::cout << "3. Traverse List1" << std::endl;
	std::cout << "4. Traverse List2" << std::endl;
	std::cout << "5. Find Intersecting Node" << std::endl;
	std::cout << "6. Exit" << std::endl;
}


void findIntersect(node root1, node root2){

	while(root1!=NULL && root2!=NULL){

		if(root1->data==root2->data){
			std::cout << "Nodes intersect at : " << root1->data << std::endl;
			return;
			}

		root1=root1->next;
		root2=root2->next;
		}

	std::cout << "No intersecting node.!"<< std::endl;

}

void process(){

	node list1=NULL, list2=NULL;
	char opt;
	int val;

	while(opt!='6'){

		dslpyMenu();
		std::cout << "Enter Option: ";
		std::cin >> opt;

		switch(opt){

			case '1':
				std::cout << "Enter Value: ";
				std::cin >> val;
				insertNode(list1, val);
				break;

			case '2':
				std::cout << "Enter Value: ";
				std::cin >> val;
				insertNode(list2, val);
				break;

			case '3':
				traverse(list1);
				break;

			case '4':
				traverse(list2);
				break;

			case '5':
				findIntersect(list1, list2);
				break;

			case '6':
				return;

			default:
				std::cout << "Invalid Option.!" << std::endl;
				break;
			}
	

		}
	

}


int main(){

	process();

}



