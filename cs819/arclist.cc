#include "arclist.h"

/*** ArcElement methods ***/

ArcElement :: ArcElement (int to) {
   rc = new Arc(to);
   next = NULL;
   prev = NULL;
}

ArcElement :: ArcElement (int to, String la) {
   rc = new LabelArc(to, la);
   next = NULL;
   prev = NULL;
}

ArcElement :: ArcElement () {
   rc = NULL;
   next = NULL;
   prev = NULL;
}

ArcElement :: ~ArcElement () {
   delete rc;
}

/***  ArcList methods ***/

ArcList :: ArcList () {
   sentinel = new ArcElement();
   sentinel->next = sentinel;
   sentinel->prev = sentinel;
}

ArcList :: ~ArcList () {
	ArcElement* current;
	ArcElement* after;

   after = sentinel->next;
   if (after == sentinel)
      delete sentinel;
   else {
      do  {
         current = after;
         after = after->next;
         delete current;
       } while ( after != sentinel );
      delete sentinel;
     }
}

ArcList :: print () {
	ArcElement* e;
	int count = 0;

   if (sentinel->next == sentinel)
      cout << " no arcs from here" << endl;
   else {
      cout << " arcs to:";
      e = sentinel->next;
      while (e != sentinel) {
         e->rc.print();
         e = e->next;
         if (e != sentinel)
            cout << ",";
         else
            cout << endl;
        }
     }
}

ArcList :: add (int to) {
	ArcElement* e;
   e = new ArcElement(to);
   e->next = sentinel;
   e->prev = sentinel->prev;
   sentinel->prev->next = e;
   sentinel->prev = e;
}

ArcList :: add (int to, String la) {
	ArcElement* e;
   e = new ArcElement(to, la);
   e->next = sentinel;
   e->prev = sentinel->prev;
   sentinel->prev->next = e;
   sentinel->prev = e;
}

ArcList :: del (int to) {
	ArcElement* e;
	int found = 0;

   e = sentinel->next;
   while (e != sentinel && !found ) {
     if (e->rc->getdest() == to)
        found = 1;
     else
        e = e->next;
   }
   if ( found && e != sentinel ){
      e->next->prev = e->prev;
      e->prev->next = e->next;
      delete e;
   }
   else
	  cout << ">>> Arc not found" << endl;
}

Arc*
ArcList :: find (int to) {
	ArcElement* e;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
      if (e->rc->getdest() == to)
         found = 1;
      else
         e = e->next;
      }
   if ( found && e != sentinel )
      return e->rc;
   else
      return NULL;
}

Arc* ArcList :: firstArc() {
   if (sentinel == sentinel->next)
      return NULL;
   else
      return sentinel->next->rc;
}

void
ArcList :: nextArc( Arc* &ptr) {
	ArcElement* e;
	int found = 0;
   e = sentinel->next;
   while (e != sentinel && !found ) {
      if (e->rc->getdest() == ptr->getdest()
       && e->rc->getlabel() == ptr->getlabel())
         found = 1;
      else
         e = e->next;
      }
   e = e->next;
   if ( found && e != sentinel )
      ptr = e->rc;
   else
      ptr = NULL;
}
