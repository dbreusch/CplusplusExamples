#include "graph.h"
#include "command.h"

/*** Constructor ***/

Command :: Command (char* newname) { name = newname; } 
Command :: Command (String newname) { name = newname; } 

/*** isCommand ***/

Command :: isCommand(char* token)
{
	if (token == name)
	  return 1;
	return 0;
}

/*** constructors ***/

Cmd_Printall :: Cmd_Printall (String name) : Command(name) {};
Cmd_Printall :: Cmd_Printall (char* name) : Command(name) {};
Cmd_1Int :: Cmd_1Int (String name) : Command(name) {};
Cmd_1Int :: Cmd_1Int (char* name) : Command(name) {};
Cmd_DelGraph :: Cmd_DelGraph (String name) : Cmd_1Int(name) {};
Cmd_DelGraph :: Cmd_DelGraph (char* name) : Cmd_1Int(name) {};
Cmd_Print :: Cmd_Print (String name) : Cmd_1Int(name) {};
Cmd_Print :: Cmd_Print (char* name) : Cmd_1Int(name) {};
Cmd_Unreach :: Cmd_Unreach (String name) : Cmd_1Int(name) {};
Cmd_Unreach :: Cmd_Unreach (char* name) : Cmd_1Int(name) {};
Cmd_2Int :: Cmd_2Int (String name) : Cmd_1Int(name) {};
Cmd_2Int :: Cmd_2Int (char* name) : Cmd_1Int(name) {};
Cmd_Graph :: Cmd_Graph (String name) : Cmd_2Int(name) {};
Cmd_Graph :: Cmd_Graph (char* name) : Cmd_2Int(name) {};
Cmd_Dag :: Cmd_Dag (String name) : Cmd_2Int(name) {};
Cmd_Dag :: Cmd_Dag (char* name) : Cmd_2Int(name) {};
Cmd_Tree :: Cmd_Tree (String name) : Cmd_2Int(name) {};
Cmd_Tree :: Cmd_Tree (char* name) : Cmd_2Int(name) {};
Cmd_Node :: Cmd_Node (String name) : Cmd_2Int(name) {};
Cmd_Node :: Cmd_Node (char* name) : Cmd_2Int(name) {};
Cmd_DelNode :: Cmd_DelNode (String name) : Cmd_2Int(name) {};
Cmd_DelNode :: Cmd_DelNode (char* name) : Cmd_2Int(name) {};
Cmd_Dfs :: Cmd_Dfs (String name) : Cmd_2Int(name) {};
Cmd_Dfs :: Cmd_Dfs (char* name) : Cmd_2Int(name) {};
Cmd_Reach :: Cmd_Reach (String name) : Cmd_2Int(name) {};
Cmd_Reach :: Cmd_Reach (char* name) : Cmd_2Int(name) {};
Cmd_Cycle :: Cmd_Cycle (String name) : Cmd_2Int(name) {};
Cmd_Cycle :: Cmd_Cycle (char* name) : Cmd_2Int(name) {};
Cmd_3Int :: Cmd_3Int (String name) : Cmd_2Int(name) {};
Cmd_3Int :: Cmd_3Int (char* name) : Cmd_2Int(name) {};
Cmd_Arc :: Cmd_Arc (String name) : Cmd_3Int(name) {};
Cmd_Arc :: Cmd_Arc (char* name) : Cmd_3Int(name) {};
Cmd_Insert :: Cmd_Insert (String name) : Cmd_3Int(name) {};
Cmd_Insert :: Cmd_Insert (char* name) : Cmd_3Int(name) {};
Cmd_DelArc :: Cmd_DelArc (String name) : Cmd_3Int(name) {};
Cmd_DelArc :: Cmd_DelArc (char* name) : Cmd_3Int(name) {};
Cmd_Path :: Cmd_Path (String name) : Cmd_3Int(name) {};
Cmd_Path :: Cmd_Path (char* name) : Cmd_3Int(name) {};
Cmd_3Int1Tok :: Cmd_3Int1Tok (String name) : Cmd_3Int(name) {};
Cmd_3Int1Tok :: Cmd_3Int1Tok (char* name) : Cmd_3Int(name) {};
Cmd_Larc :: Cmd_Larc (String name) : Cmd_3Int1Tok(name) {};
Cmd_Larc :: Cmd_Larc (char* name) : Cmd_3Int1Tok(name) {};
Cmd_DelLarc :: Cmd_DelLarc (String name) : Cmd_3Int1Tok(name) {};
Cmd_DelLarc :: Cmd_DelLarc (char* name) : Cmd_3Int1Tok(name) {};

/*** getArgs ***/

Cmd_1Int :: getArgs (UserInterface& ui) {
	ui.getInt( arg1 );
	if (ui.bad())
		return 0;
	else
		return 1;
}

Cmd_2Int :: getArgs (UserInterface& ui) {
	int rc;

	if ( (rc = Cmd_1Int::getArgs( ui )) == 1)
		{
		ui.getInt( arg2 );
		if (ui.bad())
			rc = 0;
		}
	else
		rc = 1;
	return rc;
}

Cmd_3Int :: getArgs (UserInterface& ui) {
	int rc;

	if ( (rc = Cmd_2Int::getArgs( ui )) == 1)
		{
		ui.getInt( arg3 );
		if (ui.bad())
			rc = 0;
		}
	else
		rc = 1;
	return rc;
}

Cmd_3Int1Tok :: getArgs (UserInterface& ui) {
	int rc;

	if ( (rc = Cmd_3Int::getArgs( ui )) == 1)
		{
		ui.getToken( arg4 );
		if (ui.bad())
			rc = 0;
		}
	else
		rc = 1;
	return rc;
}

Cmd_Graph :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Dag :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Tree :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Node :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Arc :: getArgs (UserInterface& ui) {
	return Cmd_3Int::getArgs( ui );
}

Cmd_Larc :: getArgs (UserInterface& ui) {
	return Cmd_3Int1Tok::getArgs( ui );
}

Cmd_Insert :: getArgs (UserInterface& ui) {
	return Cmd_3Int::getArgs( ui );
}

Cmd_DelGraph :: getArgs (UserInterface& ui) {
	return Cmd_1Int::getArgs( ui );
}

Cmd_DelNode :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_DelArc :: getArgs (UserInterface& ui) {
	return Cmd_3Int::getArgs( ui );
}

Cmd_DelLarc :: getArgs (UserInterface& ui) {
	return Cmd_3Int1Tok::getArgs( ui );
}

Cmd_Print :: getArgs (UserInterface& ui) {
	return Cmd_1Int::getArgs( ui );
}

Cmd_Printall :: getArgs (UserInterface& ui) {
	return 1;
}

Cmd_Unreach :: getArgs (UserInterface& ui) {
	return Cmd_1Int::getArgs( ui );
}

Cmd_Dfs :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Reach :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

Cmd_Path :: getArgs (UserInterface& ui) {
	return Cmd_3Int::getArgs( ui );
}

Cmd_Cycle :: getArgs (UserInterface& ui) {
	return Cmd_2Int::getArgs( ui );
}

/***********************************************************/
/*           Execute methods for all Commands              */
/***********************************************************/

Cmd_Graph :: execute (UserInterface& ui, GraphList& g_list) {
   cout << "Command " << name;
   cout << " with id " << arg1;
   cout << " and root " << arg2 << "." << endl;
   g_list.addgraph( arg1, arg2 );
}

Cmd_Dag :: execute (UserInterface& ui, GraphList& g_list) {
   cout << "Command " << name;
   cout << " with id " << arg1;
   cout << " and root " << arg2 << "." << endl;
   g_list.adddag( arg1, arg2 );
}

Cmd_Tree :: execute (UserInterface& ui, GraphList& g_list) {
   cout << "Command " << name;
   cout << " with id " << arg1;
   cout << " and root " << arg2 << "." << endl;
   g_list.addtree( arg1, arg2 );
}

Cmd_Node :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and node id " << arg2 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->addnode(arg2);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Arc :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " from " << arg2;
   cout << " to " << arg3 << "." << endl;
   g = g_list.find( arg1 );
   if (g != NULL)
      g->addarc( arg2, arg3 );
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Larc :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " from " << arg2;
   cout << " to " << arg3;
   cout << " with label " << arg4 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->addarc(arg2, arg3, arg4);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Insert :: execute (UserInterface& ui, GraphList& g_list) {
   cout << "Command " << name;
   cout << " with source id " << arg2;
   cout << " and dest id " << arg1;
   cout << " and id " << arg3 << "." << endl;
   cout << "*** The Insert Command Is Not Implemented" << endl;
}

Cmd_DelGraph :: execute (UserInterface& ui, GraphList& g_list) {
   cout << "Command " << name;
   cout << " with graph id " << arg1 << "." << endl;
   g_list.del( arg1 );
}

Cmd_DelNode :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and node id " << arg2 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->delnode(arg2);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_DelArc :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " to " << arg3;
   cout << " from " << arg2 << "." << endl;
   g = g_list.find( arg1 );
   if (g != NULL)
      g->delarc(arg2, arg3);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_DelLarc :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " to " << arg3;
   cout << " from " << arg2;
   cout << " with label " << arg4 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->delarc(arg2, arg3);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Print :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   g = g_list.find( arg1 );
   if (g != NULL)
      g.print();
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Printall :: execute (UserInterface& ui, GraphList& g_list) {
   g_list.print();
}

Cmd_Unreach :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->unreach();
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Dfs :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and start node " << arg2 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->dfs(arg2);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Reach :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and dest node " << arg2 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->reach(arg2);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Path :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and start node " << arg2;
   cout << " and dest node " << arg3 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL){
      g->path(arg2, arg3);
     }
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}

Cmd_Cycle :: execute (UserInterface& ui, GraphList& g_list) {

	Graph* g;

   cout << "Command " << name;
   cout << " with graph id " << arg1;
   cout << " and start node " << arg2 << "." << endl;
   g = g_list.find(arg1);
   if (g != NULL)
      g->cycle(arg2);
   else
      cout << ">>> Graph with id " << arg1 << " unknown." << endl;
}
