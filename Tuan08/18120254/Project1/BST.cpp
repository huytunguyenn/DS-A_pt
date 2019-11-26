#include "BST.h"

BST::BST() {
	root = NULL;
}
void BST::DeleteTree(NODE* node) {
	if (node) {		//node !=NULL
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}
}
BST::~BST() {
	DeleteTree(root);
}
void BST::Inorder(NODE* node) {
	if (node) {		//node!=NULL
		Inorder(node->left);
		cout << node->key << "  ";
		Inorder(node->right);
	}
}
void BST::Inorder_trav() {
	Inorder(root);
}
void BST::Insert(int x) {
	NODE* node = new NODE;	// node cần insert
	node->key = x;
	NODE* temp = new NODE;	// dùng để duyệt TỚI KHI = NULL
	NODE* parent = new NODE;	// node cha của node cần insert, tránh th temp=NULL
	if (!root) // root==NULL
		root = node;
	else {
		temp = root;
		while (temp) { // duyệt tới node lá, temp!=NULL
			parent = temp;
			if (x <= temp->key)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if (x <= parent->key)
			parent->left = node;
		else
			parent->right = node;
	}
}
NODE*BST::SearchNode(NODE* root, int x) {
	if (!root)
		return NULL;
	else if (root->key == x)
		return root;
	else if (x <= root->key)
		SearchNode(root->left, x);
	else
		SearchNode(root->right, x);
}
NODE* BST::Search(int x) {
	NODE* result = SearchNode(root, x);
	return result;
}
void BST::SearchNodeAll(NODE* root, int x, bool &check) {
	if (!root)
		return;
	else if (root->key == x) {
		cout << "Dia chi: " << root << endl;
		check = true; // có tồn tại phần tử x trong cây
	}
	if (x <= root->key)
		SearchNodeAll(root->left, x, check);
	else
		SearchNodeAll(root->right, x, check);
}
void BST::SearchAll(int x, bool &check) {
	SearchNodeAll(root, x, check);
}

void BST::Remove(int value) {
	NODE* DelNode = SearchNode(root, value);
	DelNode = Delete(DelNode);
}
NODE* BST::Delete(NODE* p) {
	NODE* rp = new NODE;
	NODE* f = new NODE;
	if (p == NULL)
		return NULL;
	else if (p->left == NULL && p->right != NULL)
		rp = p->right;
	else if (p->right == NULL && p->left != NULL)
		rp = p->left;
	else if (p->left == NULL && p->right == NULL) {}
	else {
		f = p;
		rp = p->right;
		while (rp != NULL) {
			f = rp;
			rp = rp->left;
		}
		if (f == p) {
			rp->left = p->left;
		}
		else {
			f->left = rp->right;
			rp->right = p->right;
			rp->left = p->left;
		}
	}
	//delete p;
	return rp;
}