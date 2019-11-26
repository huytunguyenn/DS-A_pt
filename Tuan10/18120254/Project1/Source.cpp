#include "Graph.h"
#define NMAX 100
#define MMAX 1000
int main() {
	Node* List[NMAX];
	int u, v, m, n;
	// Nhập số đỉnh và số cạnh
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		Node* p = new Node();
		p->MaNode = v;

		if (List[u] == NULL)
			List[u] = p;
		else
		{
			p->pNext1 = List[u];
			List[u] = p;
		}
	}
	return 0;
}