#include "AVLTREE.h"



AVLTREE::AVLTREE(){
	root = NULL;
}
void AVLTREE::RemoveAll(AVLNODE*& t){
	if (t != NULL) {
		RemoveAll(t->pLeft);
		RemoveAll(t->pRight);
		delete t;
	}
}
AVLTREE::~AVLTREE(){
	RemoveAll(root);
}
AVLNODE* AVLTREE::CreateNode(int Data){
	AVLNODE* pNode;
	pNode = new AVLNODE; //Xin cấp phát bộ nhớ động để tạo một phần tử (node)mới
	if (pNode == NULL) {
		return NULL;
	}
	pNode->Key = Data;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->bal = 0; //Ghi chú: giải thích ý nghĩa của thao tác này
	return pNode;
}
void AVLTREE::LeftRotate(AVLNODE*& P){
	AVLNODE* Q;
	Q = P->pRight;
	P->pRight = Q->pLeft;
	Q->pLeft = P;
	P = Q;
}
void AVLTREE::RightRotate(AVLNODE*& P){
	AVLNODE* Q;
	Q = P->pLeft;
	P->pLeft = Q->pRight;
	Q->pRight = P;
	P = Q;
}
void AVLTREE::LeftBalance(AVLNODE*& P){
	switch (P->pLeft->bal) {
	case 1: //mất cân bằng trái trái
		RightRotate(P);
		P->bal = 0;
		P->pRight->bal = 0;
		break;
	case 2: //trường hợp mất cân bằng 
		LeftRotate(P->pLeft);
		RightRotate(P);
		switch (P->bal) {
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		case 2:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		}
		P->bal = 0;
		break;
	}
}
void AVLTREE::RightBalance(AVLNODE*& P){
	switch (P->pRight->bal) {
	case 1: // trường hợp mất cân bằng
		RightRotate(P->pRight);
		LeftRotate(P);
		switch (P->bal) {
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		case 2:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		}
		P->bal = 0;
		break;
	case 2: // trường hợp mất cân bằng 
		LeftRotate(P);
		P->bal = 0;
		P->pLeft->bal = 0;
		break;
	}
}
int AVLTREE::InsertNode(int x){
	int res;
	if (root == NULL) { 
		root = CreateNode(x);
		if (root == NULL) {
			return -1; //thêm ko thành công vì thiếu bộ nhớ
		}
		return 2;//thêm thành công và làm tăng chiều cao cây
	}
	else {
		if (root->Key == x) {
			return 0; //khóa này đã tồn tại trong cây
		}
		else if (root->Key > x) {
			root = root->pLeft;
			res = InsertNode(x);
			if (res < 2) {
				return res;
			}
			switch (root->bal) { 
			case 0:
				root->bal = 1;
				return 2;
			case 1:
				LeftBalance(root);
				return 1;
			case 2:
				root->bal = 0;
				return 1;
			}
		}
		else {
			root = root->pRight;
			res = InsertNode(x);
			if (res < 2) {
				return res;
			}
			switch (root->bal) {
			case 0:
				root->bal = 2;
				return 2;
			case 1:
				root->bal = 0;
				return 1;
			case 2:
				RightBalance(root);
				return 1;
			}
		}
	}
}
void AVLTREE::Traverse(AVLNODE* t)
{
	if (t != NULL)
	{
		Traverse(t->pLeft);
		cout << t->Key << " ";
		Traverse(t->pRight);
	}
}
void AVLTREE::LNR() {
	Traverse(root);
}