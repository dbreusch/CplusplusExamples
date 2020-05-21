// ------------------------------------------------------------
//
// file:  cmdtbl.cc
// CS819
//
// Maintain an array of known commands through class CmdTbl.
// A new array will be allocated of the size passed to the
// constructor.  The array will then be populated with pointers
// to the valid commands.  On destruction, each of these pointers
// will be deleted.
// ------------------------------------------------------------

#include <assert.h>
#include <String.h>
#include "command.h"
#include "cmdtbl.h"

CmdTbl::CmdTbl( long size ) {
long ix = 0;

assert( size > 0 );
cmdtable = new Command*[ size ];				// allocate a new array
assert( cmdtable != 0 );

//
// populate the array; add new commands anywhere in this section
//
cmdtable[ ix++ ] = new Cmd_Graph("graph");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Dag("dag");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Tree("tree");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Node("node");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Arc("arc");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Larc("larc");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Insert("insert");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_DelGraph("delgraph");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_DelNode("delnode");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_DelArc("delarc");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_DelLarc("dellarc");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Print("print");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Printall("printall");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Unreach("unreach");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Dfs("dfs");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Reach("reach");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Path("path");
assert( ix <= size );
cmdtable[ ix++ ] = new Cmd_Cycle("cycle");

//
// make sure balance of array contains NULL pointers
//
for (int i  = ix; i < size; i++ )
	cmdtable[ i ] = NULL;

numCmd = --ix;					// set actual number of commands
}

CmdTbl::~CmdTbl() {

for (long ix = 0; ix <= numCmd; ix++ )		// delete the commands
	if (cmdtable[ ix ] != NULL)
		delete cmdtable[ ix ];
}

Command* CmdTbl :: isCommand( char* token ) {

Command* rc = NULL;

for  (int i=0; (i <= numCmd) && (cmdtable[i] != NULL); i++ )
	if ((*cmdtable[i]).isCommand( token )) {
		rc = cmdtable[ i ];
		break;
		}
	return rc;
}

Command* CmdTbl :: isCommand( String token ) {

Command* rc = NULL;

for  (int i=0; (i <= numCmd) && (cmdtable[i] != NULL); i++ )
	if ((*cmdtable[i]).isCommand( token )) {
		rc = cmdtable[ i ];
		break;
		}
	return rc;
}
