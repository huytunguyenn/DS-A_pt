#include "BST.h"

BST::BST() {
	root = NULL;
};
BST::~BST() {
	destroy_tree(root);
};
void BST::destroy_tree(Node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
void BST::insert(int value) {
	Node* leaf_node=new Node;
	Node* curr_node = new Node;
	Node* t = new Node;
	t->data = value;
	if (root == NULL)
		root = t; 
	else{
		curr_node = root;
		while (curr_node != NULL){
			leaf_node = curr_node;
			if (value > curr_node->data)
				curr_node = curr_node->right;
			else
				curr_node = curr_node->left;
		}
		if (value > leaf_node->data)
			leaf_node->right = t;
		else
			leaf_node->left = t;
	}
}
void BST::inorder(){
	inorder(root);
}
void BST::inorder(Node* temp){
	if (temp == NULL) 
		return;
	inorder(temp->left);
	cout << temp->data << " ";
	inorder(temp->right);
}
void BST::remove(int value){
	Node* curr_node = new Node; 
	Node* parent=new Node;
	if (root == NULL){
		cout << "Cay nhi phan rong!" << endl;
		return;
	}
	int found = false;
	curr_node = root;
	while (curr_node != NULL){
		if (curr_node->data == value){
			found = true;
			break;
		}
		parent = curr_node;
		if (value > curr_node->data)
			curr_node = curr_node->right;
		else
			curr_node = curr_node->left;
	}
	if (!found){
		cout << "Khong tim thay gia tri!" << endl;
		return;
	}
	if (curr_node->right == NULL && curr_node->left == NULL){
		if (parent->right == curr_node){
			parent->right = NULL;
			delete curr_node;
		}
		else{
			parent->left = NULL;
			delete curr_node;
		}
		return;
	}
	if (curr_node->right != NULL && curr_node->left == NULL){
		if (parent->left == curr_node){
			parent->left = curr_node->right;
			delete curr_node;
		}
		else{
			parent->right = curr_node->right;
			delete curr_node;
		}
		return;
	}
	if (curr_node->right == NULL && curr_node->left != NULL){
		if (parent->left == curr_node){
			parent->left = curr_node->right;
			delete curr_node;
		}
		else{
			parent->right = curr_node->right;
			delete curr_node;
		}
		return;
	}
	Node* check_node = curr_node->right;
	if (check_node->left == NULL){
		curr_node->data = check_node->data;
		curr_node->right = check_node->right;
		delete check_node;
	}
	else{
		Node* successor, * parent;
		parent = check_node;
		successor = check_node->left;
		while (successor->left != NULL){
			parent = successor;
			successor = successor->left;
		}
		curr_node->data = successor->data;
		parent->left = successor->right;
		delete successor;
	}
}
void BST::search(int value){
	int depth = 0;
	Node* temp = new Node;
	temp = root;
	while (temp != NULL){
		depth++;
		if (temp->data == value){
			cout <<value<< " tim thay o vi tri " << depth<<endl;
			return;
		}
		else if (temp->data > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	cout << "Khong tim thay "<<value<<endl;
	return;
}