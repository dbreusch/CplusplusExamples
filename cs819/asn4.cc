/*
	Assignment 4 -- A General Graph Tool (a.k.a. Final Project)
	David B. Reusch		05/11/94
	Eric J. Jome
	Rion M. D'Luz

	This program implements the specification for A General Graph Tool.
	It supports the following commands:
		graph, dag, tree, node, arc, larc, insert, delgraph, delnode,
		delarc, dellarc, print, printall, unreach, dfs, reach, path, cycle
	See the User's Guide for more information on command syntax.

	In this main section of the application, an instance of the CmdTbl
	class is used to hold the recognized commands.  The CmdTbl class
	provided methods for validating command names, getting command
	arguments and command execution are used here.
	The GraphList class is used as an application variable to hold
	all graphs created during execution.
	Class UserInterface encapsulates the implementation of the
	interface to user data, input and output.  It is used here to
	obtain the command token from stdin.
*/
#include "command.h"
#include "cmdtbl.h"
#include "graphlist.h"

main () {
CmdTbl cmdtbl;
Command* cmd;
UserInterface ui;
String token;
GraphList g_list;

/*
	Loop through the command table looking for a match.  if none is found,
	issue an error message.  Otherwise, attempt to get the required
	arguments from the user data.
	Return codes from getArgs:
	0:  unable to get arguments
	1:  arguments are available
	If that succeeds, attempt to execute the command with the arguments.
	Return codes from execute:
		None - error handling is done within routines
*/

ui.getCommand(token);
while ( !ui.eof() ) {
	if (( cmd = cmdtbl.isCommand( token )) != NULL)
		if ( cmd->getArgs(ui) )
			cmd->execute(ui, g_list);
		else
			cout << "Error:  bad arguments for " << cmd << endl;
	else
		cout << "Error:  '" << token << "' not recognized" << endl;
	ui.getCommand(token);
	} // while
}
