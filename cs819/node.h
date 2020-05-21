#ifndef NODE_H
#define NODE_H

#include <iostream.h>
#include <String.h>
#include "arclist.h"

/*** Node class ***/

class Node {
protected:
	int id;
	ArcList arcs;
public:
	Node(int i); 
	Node(); 
	virtual ~Node(){};
	Node(const Node&);
	const Node& operator= (const Node&);
	print();
	getid();
	addarc(int i);
	addarc(int i, String la);
	delarc(int i);
	Arc* firstArc();
	void nextArc(Arc* &ptr);
	virtual int isPseudo();
};

class PseudoNode : public Node {
protected:

/* Notes by ejj on insert */

/*	Graph nodegraph; */
/* this declaration is a problem... graph includes node and vice versa...  */
/* i am not immediately sure of how to break this long include chain...    */

/* a field created at construction time of all outward pointing arcs (ie. */
/* those with a destination of -1) might be helpful in searching or matching */
/* internal arcs for traversals. */

/* the function isPseudo(); is designed to help traversals by making it */
/* easy to identify PseudoNodes from Nodes. */

/* the = operator is not overloaded properly through the various routines. */
/* classes graph, node, arc, nodelist, arclist, nodeelement, and arcelement */
/* need them.  The general concept should have the list ones iterating and */
/* using the = of element to copy, using the = of the actual item, into  */
/* a _new_ structure of the same type.  Basically, they all say : */
/*   new <one of me>; 						           */
/*   copy my fields into it by either 'its' = 'mine' or iterating and this */

public:
	PseudoNode(int i); 
	PseudoNode(); 
	~PseudoNode(){};
	PseudoNode(const PseudoNode&);
	const PseudoNode& operator= (const PseudoNode&);
	int isPseudo();
};

#endif
