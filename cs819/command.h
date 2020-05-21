#ifndef COMMAND_H
#define COMMAND_H

#include <stream.h>
#include <stdio.h>
#include <String.h>
#include <SLList.h>
#include "ui.h"

class GraphList;

/*** Parent Class ***/

class Command {
protected:
	String name;
public: 
	Command () {};
	Command (char* newname);
	Command (String newname);
	virtual ~Command() {};
	int isCommand(char* token);
	virtual int getArgs(UserInterface& ui) {};
	virtual int execute(UserInterface& ui, GraphList& g_list) {};
};

/*** Derived Classes ***/

class Cmd_Printall : public Command {
	// no new structure
public:
	Cmd_Printall (char* name);
	Cmd_Printall (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_1Int : public Command {
protected:
	int arg1;
public:
	Cmd_1Int (char* name);
	Cmd_1Int (String name);
	virtual int getArgs (UserInterface& ui);
	virtual int execute(UserInterface& ui, GraphList& g_list) {};
};

/*******************************************************/

class Cmd_DelGraph : public Cmd_1Int {
	// no new structure
public:
	Cmd_DelGraph (char* name);
	Cmd_DelGraph (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Print : public Cmd_1Int {
	// no new structure
public:
	Cmd_Print (char* name);
	Cmd_Print (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Unreach : public Cmd_1Int {
	// no new structure
public:
	Cmd_Unreach (char* name);
	Cmd_Unreach (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_2Int : public Cmd_1Int {
protected:
	int arg2;
public:
	Cmd_2Int (char* name);
	Cmd_2Int (String name);
	virtual int getArgs (UserInterface& ui);
	virtual int execute(UserInterface& ui, GraphList& g_list) {};
};

/*******************************************************/

class Cmd_Graph : public Cmd_2Int {
	// no new structure
public:
	Cmd_Graph (char* name);
	Cmd_Graph (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Dag : public Cmd_2Int {
	// no new structure
public:
	Cmd_Dag (char* name);
	Cmd_Dag (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Tree : public Cmd_2Int {
	// no new structure
public:
	Cmd_Tree (char* name);
	Cmd_Tree (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Node : public Cmd_2Int {
	// no new structure
public:
	Cmd_Node (char* name);
	Cmd_Node (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_DelNode : public Cmd_2Int {
	// no new structure
public:
	Cmd_DelNode (char* name);
	Cmd_DelNode (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Dfs : public Cmd_2Int {
	// no new structure
public:
	Cmd_Dfs (char* name);
	Cmd_Dfs (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Reach : public Cmd_2Int {
	// no new structure
public:
	Cmd_Reach (char* name);
	Cmd_Reach (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Cycle : public Cmd_2Int {
	// no new structure
public:
	Cmd_Cycle (char* name);
	Cmd_Cycle (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_3Int : public Cmd_2Int {
protected:
	int arg3;
public:
	Cmd_3Int (char* name);
	Cmd_3Int (String name);
	virtual int getArgs (UserInterface& ui);
	virtual int execute(UserInterface& ui, GraphList& g_list) {};
};

/*******************************************************/

class Cmd_Arc : public Cmd_3Int {
	// no new structure
public:
	Cmd_Arc (char* name);
	Cmd_Arc (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Insert : public Cmd_3Int {
	// no new structure
public:
	Cmd_Insert (char* name);
	Cmd_Insert (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_DelArc : public Cmd_3Int {
	// no new structure
public:
	Cmd_DelArc (char* name);
	Cmd_DelArc (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_Path : public Cmd_3Int {
	// no new structure
public:
	Cmd_Path (char* name);
	Cmd_Path (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_3Int1Tok : public Cmd_3Int {
protected:
	String arg4;
public:
	Cmd_3Int1Tok (char* name);
	Cmd_3Int1Tok (String name);
	virtual int getArgs (UserInterface& ui);
	virtual int execute(UserInterface& ui, GraphList& g_list) {};
};

/*******************************************************/

class Cmd_Larc : public Cmd_3Int1Tok {
	// no new structure
public:
	Cmd_Larc (char* name);
	Cmd_Larc (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

/*******************************************************/

class Cmd_DelLarc : public Cmd_3Int1Tok {
	// no new structure
public:
	Cmd_DelLarc (char* name);
	Cmd_DelLarc (String name);
	int getArgs (UserInterface& ui);
	int execute(UserInterface& ui, GraphList& g_list);
};

#endif
