#include "Graph.h"


void Graph::DFS(int u, const dsk& ke) {
	// Đánh dấu đỉnh u đã được ghé thăm
	visited[u] = true;
	// Duyệt qua các đỉnh v kề với u
	for (int v : ke[u]) {
		// Nếu v chưa được thăm, gọi đệ quy dfs đỉnh v
		if (!visited[v]) 
			DFS(v, ke);
	}
}
void Graph::DFS(dsk& ke) {
	DFS(6, ke);
}
Graph::Graph()
{
	root = NULL;
}

void Graph::Init()
{
	Node* a = new Node;
	a->MaNode = 'a';
	Node* b = new Node;
	b->MaNode = 'b';
	Node* c = new Node;
	c->MaNode = 'c';
	Node* d = new Node;
	d->MaNode = 'd';
	Node* e = new Node;
	e->MaNode = 'e';
	Node* f = new Node;
	f->MaNode = 'f';
	a->pNext1 = f;
	a->pNext2 = d;
	a->pNext3 = b;
	b->pNext1 = a;
	b->pNext2 = c;
	b->pNext3 = d;
	c->pNext1 = b;
	c->pNext2 = d;
	d->pNext1 = c;
	d->pNext2 = b;
	d->pNext3 = a;
	d->pNext4 = f;
	d->pNext5 = e;
	f->pNext1 = e;
	f->pNext2 = d;
	f->pNext3 = a;
	e->pNext1 = f;
	e->pNext2 = d;
	root = a;
}


Graph::~Graph()
{
}
