#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Node.h"
#define N 100
#include <vector>
// Mảng để đánh dấu một đỉnh đã được thăm hay chưa
bool visited[N];
// Kiểu dữ liệu để lưu danh sách kề
typedef vector<vector<int>> dsk;

class Graph
{
public:
	Node* root;
	Graph();
	void Init();
	void DFS(int, const dsk& );
	void DFS(dsk&);
	~Graph();
};
#endif // !_GRAPH_H_

