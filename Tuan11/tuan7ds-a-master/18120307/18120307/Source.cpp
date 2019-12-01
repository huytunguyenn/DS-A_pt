#include "Header.h"

void DFS(Cnode* node) {
	node->CHECKED = true;
	cout << node->LABEL<<" ";
	for (list<Cnode*>::iterator it = node->LISTn.begin(); it!=node->LISTn.end();it++)
	{
		if (!(*it)->CHECKED)
		{
			DFS(*it);
		}
	}
}
void BFS(list<Cnode*> &listQUEU) {
	Cnode* first = *(listQUEU.begin());
	listQUEU.pop_front();
	cout << first->LABEL << " ";
	for (list<Cnode*>::iterator it = first->LISTn.begin(); it != first->LISTn.end(); it++)
	{
		if (!(*it)->CHECKED)
		{
			(*it)->CHECKED = true;
			listQUEU.push_back(*it);
		}
	}
	if (listQUEU.size()!=0)
	{
		BFS(listQUEU);
	}
}