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
	test.addVertex("bz");
	test.addVertex("zx");
	test.addVertex("xx");
	test.addVertex("xx");
	DFS dfs(test);
	dfs.search("bc");
	dfs.printResult();
	Digraph test2;
    std::cout << "Hello World!\n"; 
}
