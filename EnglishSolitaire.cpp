// EnglishSolitaire.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <string>
#include "digraph.h"
using namespace std;

int main()
{
	Digraph test;
	test.addVertex("bc");
	test.addVertex("dc");
	test.addVertex("de");
	test.addVertex("df");
	test.addVertex("cd");
	test.addVertex("da");
	test.addVertex("db");
	BFS bfs(test);
	bfs.search("He");
	Digraph test2;
    std::cout << "Hello World!\n"; 
}
