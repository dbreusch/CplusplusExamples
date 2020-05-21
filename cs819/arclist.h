#ifndef ARCLIST_H
#define ARCLIST_H

#include "arc.h"
#include <String.h>

/*** ArcElement class ***/

class ArcElement {
	friend class ArcList;
protected:
	Arc* rc;
	ArcElement* next;
	ArcElement* prev;
public: 
	ArcElement(int to);
	ArcElement(int to, String la);
	ArcElement();
	~ArcElement();
};

/*** ArcList class ***/

class ArcList {
	friend class ArcElement;
protected:
	ArcElement* sentinel;
public: 
	ArcList();
	~ArcList();
	print ();
	add (int to);
	add (int to, String l);
	del (int to);
	Arc* find (int to);
	Arc* firstArc();
	void nextArc( Arc* &ptr );
};

#endif
