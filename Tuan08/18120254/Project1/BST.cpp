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
void BST::SearchNodeAll(NODE* root, int x, bool &check) { // check để xuất ra thông báo 
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
void BST::FindRemove(int value) {
	NODE* curr_node = new NODE; // nút hiện tại
	NODE* parent = new NODE; // nút cha
	if (root == NULL) {
		cout << "Cay nhi phan rong!" << endl;
		return;
	}
	int found = false; // check tìm thấy giá trị hay chưa
	curr_node = root;
	while (curr_node != NULL) { // duyệt cây để tìm giá trị
		if (curr_node->key == value) {
			found = true;
			break;
		}
		parent = curr_node;
		if (value > curr_node->key)
			curr_node = curr_node->right; // duyệt sang phải
		else
			curr_node = curr_node->left; // duyệt sang trái
	}
	if (!found) { // nếu không tìm thấy giá trị
		cout << "Khong tim thay gia tri!" << endl;
		return;
	}
	if (curr_node->right == NULL && curr_node->left == NULL) { // trường hợp không có cây con => xóa nút, xóa liên kết vs nút cha
		if (parent->right == curr_node) { // nếu nút cần xóa là nút con phải của nút cha
			parent->right = NULL; // xóa nút 
			delete curr_node;
		}
		else { // nếu nút cần xóa là nút con trái của nút cha
			parent->left = NULL; // xóa nút
			delete curr_node;
		}
		return;
	}
	if (curr_node->right != NULL && curr_node->left == NULL) { // trường hợp có 1 cây con (cây con phải) => liên kết cây con và nút cha
		if (parent->left == curr_node) { // là nút con bên trái của nút cha
			parent->left = curr_node->right; // nút thế mạng là nút con phải (cây con phải)
			delete curr_node;
		}
		else {						   //  (parent->right == curr_node)
			parent->right = curr_node->right; // nút thế mạng là nút con
			delete curr_node;
		}
		return;
	}
	if (curr_node->right == NULL && curr_node->left != NULL) { // trường hợp có 1 cây con (cây con trái)
		if (parent->left == curr_node) {
			parent->left = curr_node->left; 
			delete curr_node;
		}
		else {
			parent->right = curr_node->left;
			delete curr_node;
		}
		return;
	}
	// trường hợp có 2 cây con
	NODE* check_node = curr_node->right; // xét cây con bên phải
	if (check_node->left == NULL) { // TH không nút trái 
		curr_node->key = check_node->key;
		curr_node->right = check_node->right;
		delete check_node;
	}
	else { // TH có nút trái, tìm nút trái nhất
		NODE* successor, *parent; // tìm node thế mạng 
		parent = check_node;
		successor = check_node->left;
		while (successor->left != NULL) { // node thế mạng là nút trái nhất cây con phải
			parent = successor;
			successor = successor->left;
		}
		curr_node->key = successor->key;
		parent->left = successor->right; // succcesor là trái nhất rồi, làm gì có successor->left được ^^
		delete successor;
	}
}