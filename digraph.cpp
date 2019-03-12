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

void DFS::search(const string s)
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
void DFS::search(int i)
{
	SList* p;
	for (p = _graph.adjList()[i]->next(); p != NULL; p = p->next())
	{
		if (p->data()->flag())
			continue;
		else
		{
			_length++;
			_route.push(p->data()->ele());
			p->data()->setFlag(true);
			//cout << p->data()->ele().c_str()<< p->data()->index() << endl;
			//printf("%p", &p->data()->index());
			search(p->data()->index());
			_length--;
			_route.pop();
			p->data()->setFlag(false);
		}
	}
	if (_max_length < _length)
	{
		_max_length = _length;
		_max_route = _route;
	}
}

void DFS::printResult()
{
	string route;
	if(_max_route.empty())
		cout<<"没有进行搜索，请使用search方法"<<endl;
	else
	{
		while (!_max_route.empty())
		{
			if (route.empty())
				route = _max_route.top();
			else
				route = _max_route.top() +"->"+ route;
			_max_route.pop();
		}
		cout << route.c_str() << endl;
	}
}
//template <class string>
//void Digraph<string>::addEdge(string* v1, string* v2)
//{
//	_vList.push_back(new Vertex(v1))
//}