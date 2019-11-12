#include "BST.h"
int main() {
	BST tree;
	int n;
	cout << "Nhap so phan tu: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int so;
		cout << "Nhap so: "; cin >> so;
		tree.insert(so);
	}
	cout << endl << "========" << endl;
	tree.inorder();
	cout << endl << "========" << endl;
	int delete_value;
	cout << "Nhap gia tri can xoa: "; cin >> delete_value;
	tree.remove(delete_value);
	cout << endl << "========" << endl;
	tree.inorder();
	cout << endl << "========" << endl;
	int search_value;
	cout << "Nhap gia tri can tim: "; cin >> search_value;
	tree.search(search_value);
	return 0;
}