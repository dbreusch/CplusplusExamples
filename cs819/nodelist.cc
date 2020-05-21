#include "nodelist.h"

/*** NodeElement methods ***/

NodeElement :: NodeElement (int id) {
   nd = new Node(id);
   next = NULL;
   prev = NULL;
}

NodeElement :: NodeElement () {
   nd = NULL;
   next = NULL;
   prev = NULL;
}

NodeElement :: ~NodeElement () {
   delete nd;
}

/************************************************************/

/***  NodeList methods ***/

NodeList :: NodeList () {
   sentinel = new NodeElement();
   sentinel->next = sentinel;
   sentinel->prev = sentinel;
}

NodeList :: ~NodeList () {
	NodeElement* current;
	NodeElement* after;
   after = sentinel->next;
   if (after == sentinel)
      delete sentinel;
   else {
      do {
         current = after;
         after = after->next;
         delete current;
      } while ( after != sentinel );
      delete sentinel;
     }
}

const NodeList
NodeList :: operator= (const NodeList& nl) {
	NodeElement* ne;
   ne = nl.sentinel->next;
   while (ne != nl.sentinel) {
      add(ne->nd->getid());
      ne = ne->next;
     }
   return *this;
}

NodeList :: print () {
	NodeElement* e;
	int count = 0;

   if (sentinel->next == sentinel)
      cout << "There are no nodes for this graph." << endl;
   else {
      e = sentinel->next;
      while (e != sentinel) {
         e->nd->print();
         e = e->next;
        }
      cout << endl;
     }
}

NodeList :: add (int id) {
	NodeElement* e;
	Node* ntmp;

   ntmp = find(id);
   if (ntmp != NULL){
      cout << ">>> Cannot create two nodes with the";
      cout << " same id in the same graph." << endl;
     }
   else{
      e = new NodeElement(id);
      e->next = sentinel;
      e->prev = sentinel->prev;
      sentinel->prev->next = e;
      sentinel->prev = e;
     }
}

NodeList :: del (int i) {
	NodeElement* e;
	int found = 0;

   e = sentinel->next;
   while (e != sentinel && !found ) {
     if (e->nd->getid() == i)
        found = 1;
     else
        e = e->next;
   }
   if ( found && e != sentinel ){
      e->next->prev = e->prev;
      e->prev->next = e->next;
      delete e;
   }
}

Node*
NodeList :: find (int i) {
	NodeElement* e;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
      if (e->nd->getid() == i)
         found = 1;
      else
         e = e->next;
      }
   if ( found && e != sentinel )
      return e->nd;
   else
      return NULL;
}

Node*
NodeList :: firstNode() {
   if (sentinel == sentinel->next)
      return NULL;
   else
      return sentinel->next->nd;
}

void
NodeList :: nextNode (Node* &ptr) {
	NodeElement* e;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
      if (e->nd->getid() == ptr->getid())
         found = 1;
      else
         e = e->next;
      }
   e = e->next;
   if ( found && e != sentinel )
      ptr = e->nd;
   else
      ptr = NULL;
}

