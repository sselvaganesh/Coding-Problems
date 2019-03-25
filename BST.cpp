#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

typedef struct nodeTemplate{
	int data;
	nodeTemplate* left;
	nodeTemplate* right;

}* node;

void heightCount(node root, std::unordered_map<int, int>& myMap, int idx){

	if(root==NULL){
		return;
		}

	if(myMap.find(idx)==myMap.end()){
		myMap[idx]=0;
		}
	myMap[idx]+=root->data;
	
	heightCount(root->left, myMap, idx+1);
	heightCount(root->right, myMap, idx-1);

}

void levelCount(node root, std::unordered_map<int, int>& myMap, int idx){

	if(root==NULL){
		return;
		}

	idx++;
	if(myMap.find(idx)==myMap.end()){
		myMap[idx]=0;
		}

	myMap[idx]+=root->data;
	levelCount(root->left, myMap, idx);
	levelCount(root->right, myMap, idx);
}


void levelOrderCount(node root){

	std::unordered_map<int, int> myMap;
	int count=-1;

	levelCount(root, myMap, count);

	std::cout << "Level Order Count :" << std::endl;

	for(auto &val: myMap){
		std::cout << val.first << '\t' << val.second << std::endl;
		}

	//-------------------------//


	std::cout << "Hight Order Count :" << std::endl;

	myMap.erase(myMap.begin(), myMap.end());

	heightCount(root, myMap, 0);

	for(auto &val: myMap){
		std::cout << val.first << '\t' << val.second << std::endl;
		}


}

void inOrder(node root){

	if(root==NULL){
		return;
		}
	else{

		inOrder(root->left);
		std::cout << root->data << '\t';
		inOrder(root->right);
		}

}


void preOrder(node root){

	if(root==NULL){
		return;
		}
	else{

		std::cout << root->data << '\t';
		preOrder(root->left);
		preOrder(root->right);
		}

}


void postOrder(node root){

	if(root==NULL){
		return;
		}
	else{
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->data << '\t';
		}

}


void printTree(node root){

	std::cout << "In-Order Traversal:" << std::endl;
	inOrder(root);
	std::cout << std::endl;

	std::cout << "Pre-Order Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;

	std::cout << "Post-Order Traversal:" << std::endl;
	postOrder(root);
	std::cout << std::endl;

}

node createNode(int val){

	node newNode = new nodeTemplate;
	
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = val;
	
	return newNode;

}


node getNodePos(node root, int val){

	if(root->data > val){

		if(root->left==NULL){
			return root;
			}
		else {
			getNodePos(root->left, val);
			}

		}

	else {

		if(root->right==NULL){
			return root;
			}
		else {
			getNodePos(root->right, val);
			}

		}

}


void insertNode(node& root){

	std::cout << "Enter Value: ";
	
	int val;
	std::cin >> val;

	node temp = createNode(val);

	if(root==NULL){
		root=temp;
		}

	else {	
		node curPos = getNodePos(root, val);	

		if(curPos->data > val){
			curPos->left = temp;	
			}
		else {
			curPos->right = temp;	
			}

		}

	std::cout << "Node inserted successfully.!" << std::endl;

}


void insertNode(node& root, int val){

	node temp = createNode(val);

	if(root==NULL){
		root=temp;
		}

	else {	
		node curPos = getNodePos(root, val);	

		if(curPos->data > val){
			curPos->left = temp;	
			}
		else {
			curPos->right = temp;	
			}

		}

}

void loadNodes(node& root){

	std::vector<int> inpVec = {20, 15, 10, 6, 11, 18, 16, 19, 30, 25, 23, 28, 40, 35, 50};

	for(int &val: inpVec){
		insertNode(root, val);
		}

	std::cout << "Node loaded successfully.!" << std::endl;

}



void deleteNodeWithNewValue(node parent, node curNode, node newValue){

	if(parent->left==curNode){
		parent->left=newValue;
		}

	else {
		parent->right=newValue;
		}

	delete curNode;

	std::cout << "Node deleted successfully...!!!" << std::endl;

}


void checkAndDelete(node parent, node curNode){

	//else, check if howmany childs are there for the node
	if(curNode->left==NULL && curNode->right==NULL){		//No child
		deleteNodeWithNewValue(parent, curNode, NULL);
		}

	else if (curNode->left !=NULL && curNode->right==NULL){		//Has 1 child (Left)
		deleteNodeWithNewValue(parent, curNode, curNode->left);
		}

	else if (curNode->left ==NULL && curNode->right!=NULL){		//Has 1 child (Right)
		deleteNodeWithNewValue(parent, curNode, curNode->right);
		}

}


void deleteNode(node root){
	
	//If tree is empty
	if(root==NULL){
		std::cout << "No element in the binary tree...!!!! Add element first..!!" << std::endl;
		return;
		}


	//Get the element to delete
	int delVal;
	std::cout << "Enter node to be deleted: ";
	std::cin >> delVal;

	node parent=root; 
	node curNode=root;
	int curVal;

	//check element exists in the tree
	while(curNode != NULL){

		curVal = curNode->data;
		
		if(curVal==delVal){
			break;
			}

		parent = curNode;

		if(curNode->data > delVal){ 		
			curNode = curNode->left;
			}
		else {
			curNode = curNode->right;
			}

		}


	//if no, return...print error msg
	if(curVal != delVal){
		std::cout << "Element not found in the binary tree..!!!" << std::endl;
		return;
		}


	if(curNode->left !=NULL && curNode->right !=NULL) {		//Has 2 childs

		//Get the new value to replace.
		node tempParent = curNode->right;
		node tempNode =curNode->right;
		int newVal = tempNode->data;

		while(tempNode->left != NULL){
			tempParent = tempNode;
			tempNode=tempNode->left;
			newVal = tempNode->data;		
			}
	
		curNode->data = newVal;
		checkAndDelete(tempParent, tempNode);

		}

	else {								//Else..Other Conditions
		checkAndDelete(parent, curNode);
		}

	
}


void getCount(node root, int& count, std::stack<bool>& uniValStack){

	if(root==NULL){
		return;
		}

	getCount(root->left, count, uniValStack);
	getCount(root->right, count, uniValStack);


	//For non-leaf nodes
	if(root->left==NULL && root->right==NULL){
		count++;
		uniValStack.push(true);
		}

	//Parent with only right child	
	else if(root->left==NULL && root->right != NULL){

		bool rightTree = uniValStack.top();
		uniValStack.pop();

		if(root->data==root->right->data && rightTree){
			count++;
			uniValStack.push(true);
			}
		else {
			uniValStack.push(false);
			}

		}


	//Parent with only left child
	else if(root->left!=NULL && root->right == NULL){

		bool leftTree = uniValStack.top();
		uniValStack.pop();

		if(root->data==root->left->data && leftTree){
			count++;
			uniValStack.push(true);
			}
		else {
			uniValStack.push(false);
			}

		}

	//Parent with both the childs
	else {

		bool left = uniValStack.top();
		uniValStack.pop();

		bool right = uniValStack.top();
		uniValStack.pop();

		if(left && right && root->data==root->left->data && root->data==root->right->data){
			count++;
			uniValStack.push(true);
			}

		else {
			uniValStack.push(false);
			}

		}

}


void uniValTreeCount(node root){

	int count=0;
	std::stack<bool> uniValStack;

	getCount(root, count, uniValStack);	

	std::cout << "Unival Tree Count: " << count << std::endl;

}

void printMenu(){

	std::cout << "1. Traverse Tree" << std::endl;
	std::cout << "2. Load Some Values" << std::endl;
	std::cout << "3. Insert Node" << std::endl;
	std::cout << "4. Delete Node" << std::endl;
	std::cout << "5. Level/Hight Order Count" << std::endl;
	std::cout << "6. UniVal Tree Count" << std::endl;
	std::cout << "7. Exit" << std::endl;

	std::cout << "Enter Option: ";

}

void binaryTreeProcessing(node root){

	int opt;

	while(opt !=7){

		printMenu();
		std::cin >> opt;

		switch(opt){

			case 1:
				printTree(root);
				break;

			case 2:
				loadNodes(root);
				break;	

			case 3:
				insertNode(root);
				break;

			case 4:
				deleteNode(root);
				break;

			case 5:
				levelOrderCount(root);
				break;

			case 6:
				uniValTreeCount(root);
				break;

			case 7:
				break;


			default:
				std::cout << "Invalid Option..!!!" << std::endl;
				break;

			}

		
		}


}


int main(){

	node root = NULL;

	binaryTreeProcessing(root);

	return 0;
}



