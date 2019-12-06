#include "AVLTREE.h"

AVLTREE::AVLTREE(){
	root = NULL;
}
void AVLTREE::RemoveAll(AVLNODE* t){
	if (t != NULL) {
		RemoveAll(t->left);
		RemoveAll(t->right);
		delete t;
	}
}
AVLTREE::~AVLTREE(){
	RemoveAll(root);
}
AVLNODE* AVLTREE::CreateNode(int Data){
	AVLNODE* pNode= new AVLNODE; 
	if (pNode == NULL) {
		return NULL;
	}
	pNode->key = Data;
	pNode->left = NULL;
	pNode->right = NULL;
	pNode->height = 1; 
	return pNode;
}
int max(int a, int b){
	return (a > b) ? a : b;
}
AVLNODE* AVLTREE::LeftRotate(AVLNODE* root){
	// xoay
	AVLNODE* p;
	p = root->right;
	root->right = p->left;
	p->left = root;
	// cập nhật chiều cao
	root->height = max(root->left->height,root->right->height) + 1;
	p->height = max(p->left->height,p->right->height) + 1;
	return p; // return p rồi cho root = leftrotate();
}
AVLNODE* AVLTREE::RightRotate(AVLNODE* root){
	AVLNODE* p;
	p = root->left;
	p->left = root->right;
	p->right = root;
	// cập nhật chiều cao
	root->height = max(root->left->height, root->right->height) + 1;
	p->height = max(p->left->height, p->right->height) + 1;
	return p; // return p rồi cho root = leftrotate();
}
int getBalance(AVLNODE* N){
	if (N == NULL)
		return 0;
	else if (N->left == NULL&& N->right != NULL)
		return -N->right->height;
	else if (N->right == NULL&& N->left != NULL)
		return N->left->height;
	else
	return N->left->height - N->right->height;
} 
void AVLTREE::InsertNode(int key) {
	root = Insert(root, key);
}
AVLNODE* AVLTREE::Insert(AVLNODE* node, int key){
	if (node == NULL)
		return(CreateNode(key));
	// thêm 1 phần tử vào cây bst
	if (key < node->key)
		node->left = Insert(node->left, key);
	else
		node->right = Insert(node->right, key);
	
	if (node->left==NULL && node->right!=NULL) {
		node->height = 1 + node->right->height;
	}
	else if (node->left != NULL && node->right== NULL) {
		node->height = 1 + node->left->height;
	}
	else
		node->height = 1 + max(node->left->height, node->right->height);

	int balance = getBalance(node);

	// Cây mất cân bằng
	// Left Left   
	if (balance > 1 && key < node->left->key)
		return RightRotate(node);

	// Right Right 
	if (balance < -1 && key > node->right->key)
		return LeftRotate(node);

	// Left Right 
	if (balance > 1 && key > node->left->key){
		node->left = LeftRotate(node->left);
		return RightRotate(node);
	}

	// Right Left 
	if (balance < -1 && key < node->right->key){
		node->right = RightRotate(node->right);
		return LeftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
void AVLTREE::Traverse(AVLNODE* t){
	if (t != NULL){
		Traverse(t->left);
		cout << t->key << " ";
		Traverse(t->right);
	}
}
void AVLTREE::LNR() {
	Traverse(root);
}