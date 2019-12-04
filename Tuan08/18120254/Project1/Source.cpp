#include "Header.h"
void Menu(BST &tree) {
	int choice;
	do {
		do {
			system("cls");
			cout << "== BINARY SEARCH TREE ==" << endl;
			cout << "0. Thoat" << endl;
			cout << "1. Them 1 nut vao cay" << endl;
			cout << "2. Duyet cay" << endl;
			cout << "3. Xoa 1 nut trong cay" << endl;
			cout << "4. Tim vi tri nut trong cay" << endl;
			cout << "5. Tim vi tri tat ca cac nut trong cay" << endl;
			cout << "Lua chon: ";
			cin >> choice;
			if (!(choice >= 0 && choice < 6)) {
				cout << "Vui long nhap lai" << endl;
				system("Pause");
			}
		} while (!(choice >= 0 && choice < 6));
		switch (choice) {
		case 0: {
			break;
		}
		case 1: {
			int x;
			cout << "Nhap gia tri phan tu them vao: ";
			cin >> x;
			tree.Insert(x);
			break;
		}
		case 2: {
			tree.Inorder_trav();
			break;
		}
		case 3: {
			int x;
			cout << "Nhap gia tri muon xoa: ";
			cin >> x;
			tree.FindRemove(x);
			break;
		}
		case 4: {
			int x;
			cout << "Nhap gia tri muon tim: ";
			cin >> x;
			cout << "Gia tri: " << x << endl;
			if (tree.Search(x) == NULL)
				cout << "Khong tim thay phan tu " << x << " trong cay" << endl;
			else {
				NODE* temp = tree.Search(x);
				cout << "Dia chi: " << temp << endl;
			}
			break;
		}
		case 5: {
			bool check = false;
			int x;
			cout << "Nhap gia tri muon tim: ";
			cin >> x;
			cout << "Gia tri: " << x << endl;
			tree.SearchAll(x, check);
			if (check == false)
				cout << "Khong tim thay phan tu " << x << " trong cay" << endl;
			break;
		}
		}
		system("pause");
	} while (choice != 0);
}