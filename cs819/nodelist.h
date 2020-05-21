#ifndef NODELIST_H
#define NODELIST_H

#include "node.h"

/*** NodeElement class ***/

class NodeElement {
	friend class NodeList;
protected:
	Node* nd;
	NodeElement* next;
	NodeElement* prev;
public: 
	NodeElement(int id);
	NodeElement();
	~NodeElement();
};

/*** NodeList class ***/

class NodeList {
	friend class NodeElement;
protected:
	NodeElement* sentinel;
public: 
	NodeList();
	~NodeList();
	const NodeList operator= (const NodeList&);
	print ();
	add (int i);
	del (int i);
	Node* find (int i);
	Node* firstNode();
	void nextNode( Node* &ptr );
};

#endif
