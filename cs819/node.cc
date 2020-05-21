#include "node.h"

/*** Node methods ***/

Node::Node(int i) {
   id = i;
}

Node::Node() {
   id = -1;
}

Node::Node (const Node& n) {
   id = n.id;
}

const Node&
Node::operator= (const Node& n) {
   id = n.id;
   return *this;
}

Node::print() {
   cout << "   Node " << id;
   arcs.print();
}

Node::getid() {
   return id;
}

Node::addarc(int i) {
	Arc* tmp;
	int exist = 0;
   tmp = arcs.firstArc();
   while (tmp != NULL && !exist) {
      if (tmp->getdest() == i && tmp->getlabel() == "")
         exist = 1;
      arcs.nextArc(tmp);
     }
   if (!exist)
      arcs.add(i);
   else
      cout << ">>>  Only one unlabeled arc between nodes is allowed." << endl;
}

Node::addarc(int i, String la) {
	Arc* tmp;
	int exist = 0;
   tmp = arcs.firstArc();
   while (tmp != NULL && !exist) {
      if (tmp->getdest() == i && tmp->getlabel() == la)
         exist = 1;
      arcs.nextArc(tmp);
     }
   if (!exist)
      arcs.add(i, la);
   else
      cout << ">>> Labeled arcs between nodes must be unique." << endl;
}

Node::delarc(int i) {
   arcs.del(i);
}

Arc*
Node :: firstArc() {
	Arc* ptr;
   ptr = arcs.firstArc();
   return ptr;
}

void Node :: nextArc(Arc* &ptr) {
   arcs.nextArc(ptr);
}

Node::isPseudo() {
   return 0;
}

/*** PseudoNode methods ***/

PseudoNode::PseudoNode(int i) : Node(i) {
}

PseudoNode::PseudoNode() : Node() {
}

PseudoNode::PseudoNode (const PseudoNode& pn) {
   id = pn.id;
}

const PseudoNode&
PseudoNode::operator= (const PseudoNode& pn) {
   id = pn.id;
   return *this;
}

PseudoNode::isPseudo() {
   return 1;
}
