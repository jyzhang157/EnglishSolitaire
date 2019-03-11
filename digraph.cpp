#include "digraph.h"

void SList::insert(Vertex* v)
{
	SList* ptr = new SList(v);
	SList* ptr_tmp = this->_next;
	this->_next = ptr;
	ptr->_next = ptr_tmp;
}

inline bool isConnect(string v1, string v2)
{
	if (v1.back() == v2.front())
		return true;
	else
		return false;
}

void Digraph::addVertex(string v)
{
	Vertex* p = new Vertex(v);
	_vList.push_back(p);
	p->setIndex(_vList.size() - 1);
	_V_count++;
	_adj.push_back(new SList());
	for (int i = 0; i < _vList.size(); i++)
	{
		if (isConnect(_vList[i]->ele(), v))
		{
			_adj[i]->insert(p);
			_E_count++;
		}
		if (isConnect(v, _vList[i]->ele()))
		{
			_adj.back()->insert(_vList[i]);
			_E_count++;
		}
	}
}

void BFS::search(const string s)
{
	
	int i=_graph.find(s);
	if (i<0)
	{
		cout << "没有找到对应的单词" << endl;
		return;
	}
	_graph.vList()[i]->setFlag(true);
	_route.push(_graph.vList()[i]->ele());
	search(_graph.vList()[i]->index());
	_route.pop();
	_graph.vList()[i]->setFlag(false);
	return;
}
void BFS::search(int i)
{
	//_graph.vList()[i]->setFlag(true);
	//_route.push(_graph.vList()[i]->ele());
	//search(_graph.vList()[i]->index());
	//_route.pop();
	//_graph.vList()[i]->setFlag(false);

	//cout << "没有找到对应的单词" << endl;
	//return;
}

//template <class string>
//void Digraph<string>::addEdge(string* v1, string* v2)
//{
//	_vList.push_back(new Vertex(v1))
//}