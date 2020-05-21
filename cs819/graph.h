#ifndef GRAPH_H
#define GRAPH_H

#include <iostream.h>
#include <SLList.h>
#include <String.h>
#include "nodelist.h"
#include "graphlist.h"

/*** Graph class ***/

class Graph {
protected:
	int id;
	Node* rootnode;
	NodeList nodes;

	SLprint(SLList<int>& list);
	findId(int nodeId, SLList<int>& list);
	virtual void do_dfs( int nodeId, SLList<int>& visited);
	virtual int do_path( int fromNode, int toNode, SLList<int>& visited, 
		SLList<int>& route);
	virtual int do_cycle( int fromNode, int startNode,
		SLList<int>& visited, SLList<int>& route);
public:
	Graph(int i, int root); 
	Graph(); 
	virtual ~Graph(){};
	Graph(const Graph&);
	const Graph& operator= (const Graph&);
	virtual print();
	virtual getid();
	virtual getRootId();
	virtual addnode(int i);
	virtual delnode(int i);
	virtual addarc(int from_id, int to_id);
	virtual addarc(int from_id, int to_id, String la);
	virtual delarc(int nodeid, int i);

	virtual void dfs(int nodeId);
	virtual void unreach();
	virtual void reach(int destId);
	virtual void path(int fromNode, int toNode);
	virtual void cycle(int id);
};

class Dag : public Graph {
public:
	Dag(int i, int root):Graph(i,root){}; 
	Dag():Graph(){}; 
	virtual ~Dag(){};
	virtual print();
	virtual addarc(int from_id, int to_id);
	virtual addarc(int from_id, int to_id, String la);
};

class Tree : public Dag {
	findchildren(SLList<int>& children);
public:
	Tree(int i, int root):Dag(i,root){}; 
	Tree():Dag(){}; 
	virtual ~Tree(){};
	virtual print();
	virtual addarc(int from_id, int to_id);
	virtual addarc(int from_id, int to_id, String la);
};

#endif
