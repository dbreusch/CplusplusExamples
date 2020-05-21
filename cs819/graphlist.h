#ifndef GRAPHLIST_H
#define GRAPHLIST_H

class Graph;

/*** GraphElement class ***/

class GraphElement {
	friend class GraphList;
protected:
	Graph* grph;
	GraphElement* next;
	GraphElement* prev;
public: 
	GraphElement(Graph* g);
	GraphElement();
	~GraphElement();
};

/*** GraphList class ***/

class GraphList {
	friend class GraphElement;
protected:
	GraphElement* sentinel;
public: 
	GraphList();
	~GraphList();
	print ();
	addgraph (int i, int root);
	adddag (int i, int root);
	addtree (int i, int root);
	del (int i);
	Graph* find (int i);
};

#endif
