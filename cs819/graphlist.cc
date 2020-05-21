#include <SLList.h>
#include "graph.h"
#include "graphlist.h"

/*** GraphElement methods ***/

GraphElement :: GraphElement (Graph* g) {
   grph = g;
   next = NULL;
   prev = NULL;
}

GraphElement :: GraphElement () {
   grph = NULL;
   next = NULL;
   prev = NULL;
}

GraphElement :: ~GraphElement () {
   delete grph;
}

/************************************************************/

/***  GraphList methods ***/

GraphList :: GraphList () {
   sentinel = new GraphElement();
   sentinel->next = sentinel;
   sentinel->prev = sentinel;
}

GraphList :: ~GraphList () {
	GraphElement* current;
	GraphElement* after;
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

GraphList :: print () {
	GraphElement* e;
	int count = 0;

   if (sentinel->next == sentinel)
      cout << "GraphList empty." << endl;
   else {
      cout << "GraphList" << endl;
      cout << "---------" << endl;
      e = sentinel->next;
      while (e != sentinel) {
         e->grph.print();
         e = e->next;
        }
     }
}

GraphList :: addgraph (int i, int root) {
	GraphElement* e;
	Graph* gtmp;

   gtmp = find(i);
   if (gtmp != NULL)
      cout << ">>> Cannot create two graphs with same id." << endl;
   else{
      gtmp = new Graph(i, root);
      e = new GraphElement(gtmp);
      e->next = sentinel;
      e->prev = sentinel->prev;
      sentinel->prev->next = e;
      sentinel->prev = e;
     }
}

GraphList :: adddag (int i, int root) {
	GraphElement* e;
	Graph* gtmp;
	Dag* dtmp;
   gtmp = find(i);
   if (gtmp != NULL) 
      cout << ">>> Cannot create two graphs with same id." << endl;
   else{
      dtmp = new Dag(i, root);
      e = new GraphElement(dtmp);
      e->next = sentinel;
      e->prev = sentinel->prev;
      sentinel->prev->next = e;
      sentinel->prev = e;
     }
}

GraphList :: addtree (int i, int root) {
	GraphElement* e;
	Graph* gtmp;
	Tree* ttmp;
   gtmp = find(i);
   if (gtmp != NULL)
      cout << ">>> Cannot create two graphs with same id." << endl;
   else{
      ttmp = new Tree(i, root);
      e = new GraphElement(ttmp);
      e->next = sentinel;
      e->prev = sentinel->prev;
      sentinel->prev->next = e;
      sentinel->prev = e;
     }
}

GraphList :: del (int i) {
	GraphElement* e;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
     if (e->grph.getid() == i)
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

Graph*
GraphList :: find (int i) {
	GraphElement* e;
	Graph empty;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
      if (e->grph.getid() == i)
         found = 1;
      else
         e = e->next;
      }
   if ( found && e != sentinel )
      return e->grph;
   else
      return NULL;
}
