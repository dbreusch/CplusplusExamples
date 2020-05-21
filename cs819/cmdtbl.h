// ------------------------------------------------------------
// header file for cmdtbl.cc
//
// file:  cmdtbl.h
// CS819
//
// ------------------------------------------------------------

#ifndef CMDTBL_H
#define CMDTBL_H

class CmdTbl {
public:
Command** cmdtable;				// array of Command pointers
long numCmd;					// actual number of commands loaded

CmdTbl( long size = 30 );		// default size of table = 30 commands
~CmdTbl();
Command* isCommand(char* token);
Command* isCommand(String token);
};

#endif
