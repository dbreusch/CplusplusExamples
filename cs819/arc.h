#ifndef ARC_H
#define ARC_H

#include <iostream.h>
#include <String.h>

/*** Arc class ***/

class Arc {
protected:
	int dest;
public:
	Arc(int to); 
	Arc(); 
	virtual ~Arc(){};
	Arc(const Arc&);
	const Arc& operator= (const Arc&);
	virtual print();
	getdest();
        virtual String getlabel();
};

class LabelArc : public Arc {
	String label;
public:
	LabelArc(int to, String l); 
	LabelArc(); 
	virtual ~LabelArc(){};
	LabelArc(const LabelArc&);
	const LabelArc& operator= (const LabelArc&);
	print();
        String getlabel();
};

#endif
