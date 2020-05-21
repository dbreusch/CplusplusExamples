#include "arc.h"

/*** Arc methods ***/

Arc::Arc(int to) {
   dest = to;
}

Arc::Arc() {
   dest = -1;
}

Arc::Arc (const Arc& a) {
   dest = a.dest;
}

const Arc&
Arc::operator= (const Arc& a) {
   dest = a.dest;
   return *this;
}

Arc::print() {
   cout << " " << dest;
}

Arc::getdest() {
   return dest;
}

String
Arc::getlabel() {
   return "";
}

/*** LabelArc methods ***/

LabelArc::LabelArc(int to, String l) : Arc(to){
   label = l;
}

LabelArc::LabelArc():Arc(-1) {
   label = "";
}

LabelArc::LabelArc (const LabelArc& la) {
   dest = la.dest;
   label = la.label;
}

const LabelArc&
LabelArc::operator= (const LabelArc& la) {
   dest = la.dest;
   label = la.label;
   return *this;
}

LabelArc::print() {
   cout << " " << dest << " with label " << label;
}

String
LabelArc::getlabel() {
   return label;
}
