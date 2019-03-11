#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_



#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

class Vertex
{
public:
    Vertex(string p):_ele(p){};
    ~Vertex() {};
	string ele(){ return _ele; }
    string ele() const {return _ele;}//这里注意
	bool find(string s) { return _ele == s; }
	const bool flag() { return _flag; }
	void setFlag(bool f) { _flag = f; }
	const bool index() { return _index; }
	void setIndex(int i) { _index = i; }

private:
	bool _flag;
    string _ele;
	int _index;
};

class SList
{
public:
    SList() {};
	SList(Vertex* v1):_data(v1){};
    ~SList() {};
    const Vertex* data() {return _data;}
    const SList* next() {return _next;}
	void insert(Vertex* v);

private:
    Vertex* _data;
    SList* _next;
};


class Digraph
{
public:
    Digraph():_V_count(0), _E_count(0){};
    ~Digraph() {};
	int V() { return _V_count; }
	int E() { return _E_count; }
	int find(string s)
	{
		for (int i = 0; i < _vList.size(); i++)
			if (_vList[i]->find(s))
				return i;
		return -1;
	}

	void addVertex(string v);
	const vector<SList*>& adjList() { return _adj; }
	const vector<Vertex*> & vList() { return _vList; };


private:
    vector<SList*> _adj;
    vector<Vertex*> _vList;
	//map<string*, list<string*>> graphList;
    int _V_count;//记录节点数量
    int _E_count;//记录边的数量

	//void addEdge(string* v1, string* v2);
};

class BFS
{
public:
	BFS(Digraph& graph) :_graph(graph) {};
	~BFS() {};
	void search(const string s);
	void search(int index);
private:
	Digraph& _graph;
	stack<string> _route;
	int _max_length;
	int _length;
};


#endif // !_DIGRAPH_H_