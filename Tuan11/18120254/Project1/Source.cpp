#include "Header.h"
void DFS(Node* node) {
	node->CHECKED = true;
	cout << node->LABEL << " ";
	for (list<Node*>::iterator it = node->LISTn.begin(); it != node->LISTn.end(); it++){
		if (!(*it)->CHECKED){
			DFS(*it);
		}
	}
}
void BFS(list<Node*> &listQUEU) {
	Node* first = *(listQUEU.begin());
	listQUEU.pop_front();
	cout << first->LABEL << " ";
	for (list<Node*>::iterator it = first->LISTn.begin(); it != first->LISTn.end(); it++){
		if (!(*it)->CHECKED){
			(*it)->CHECKED = true;
			listQUEU.push_back(*it);
		}
	}
	if (listQUEU.size() != 0){
		BFS(listQUEU);
	}
}
void runbfs() {
	Node* a = new Node("a");
	Node* b = new Node("b");
	Node* c = new Node("c");
	Node* d = new Node("d");
	Node* e = new Node("e");
	Node* f = new Node("f");
	a->LISTn.push_back(f);
	a->LISTn.push_back(d);
	a->LISTn.push_back(b);

	b->LISTn.push_back(c);

	c->LISTn.push_back(d);

	d->LISTn.push_back(b);

	e->LISTn.push_back(d);
	e->LISTn.push_back(f);

	f->LISTn.push_back(d);


	list<Node*> list;
	a->CHECKED = true;
	list.push_back(a);
	BFS(list);
}
void rundfs() {
	Node* a = new Node("a");
	Node* b = new Node("b");
	Node* c = new Node("c");
	Node* d = new Node("d");
	Node* e = new Node("e");
	Node* f = new Node("f");
	a->LISTn.push_back(f);
	a->LISTn.push_back(d);
	a->LISTn.push_back(b);

	b->LISTn.push_back(a);
	b->LISTn.push_back(d);
	b->LISTn.push_back(c);


	c->LISTn.push_back(b);
	c->LISTn.push_back(d);

	d->LISTn.push_back(c);
	d->LISTn.push_back(b);
	d->LISTn.push_back(a);
	d->LISTn.push_back(f);
	d->LISTn.push_back(e);

	e->LISTn.push_back(d);
	e->LISTn.push_back(f);

	f->LISTn.push_back(e);
	f->LISTn.push_back(d);
	f->LISTn.push_back(a);
	DFS(a);
}