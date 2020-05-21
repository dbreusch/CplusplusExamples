#include "graph.h"

/*** Graph methods ***/

Graph::Graph(int i, int root) {
   id = i;
   nodes.add(root);
   rootnode = nodes.find(root);
}

Graph::Graph() {
   id = -1;
   nodes.add(-1);
   rootnode = nodes.find(-1);
}

Graph::Graph (const Graph& g) {
   id = g.id;
   nodes = g.nodes;
   rootnode = nodes.find(g.rootnode->getid());
}

const Graph&
Graph::operator= (const Graph& g) {
   id = g.id;
   nodes = g.nodes;
   rootnode = nodes.find(g.rootnode->getid());
   return *this;
}

Graph::print() {
   cout << " Graph with id " << id << ":" << endl;
   return nodes.print();
}

Graph::getid() {
   return id;
}

Graph::addnode(int i) {
   nodes.add(i);
}

Graph::delnode(int i) {
	Node* tmpnode;
	Arc* tmparc;
   if (rootnode->getid() == i)
      cout << ">>> Cannot remove root node from graph." << endl;
   else if (nodes.find(i) == NULL)
      cout << ">>> No such node in graph." << endl;
   else {
      nodes.del(i);
      tmpnode = nodes.firstNode();
      while ( tmpnode != NULL ) {
         tmparc = tmpnode.firstArc();
         while ( tmparc != NULL ) {
            if (tmparc.getdest() == i)
               tmpnode.delarc(i);
            tmpnode.nextArc(tmparc);
           }
         nodes.nextNode(tmpnode);
        }
     }
}

Graph::addarc(int from_id, int to_id) {
	Node* from_node;
	Node* to_node;

   if (to_id != -1) {
	   to_node = nodes.find(to_id);
	   if (to_node == NULL) {
		  cout << ">>> NOTE: Automatically creating node " << to_id
			   << "." << endl;
		  nodes.add(to_id);
		 }
      }
   else
	  cout << ">>> Creating pseudo arc" << endl;

   from_node = nodes.find(from_id);
   if (from_node == NULL) {
      cout << ">>> NOTE: Automatically creating node " << from_id 
		   << "." << endl;
      nodes.add(from_id);
      from_node = nodes.find(from_id);
     }
   from_node->addarc(to_id);
}

Graph::addarc(int from_id, int to_id, String arclabel) {
	Node* from_node;
	Node* to_node;

   if (to_id != -1) {
	   to_node = nodes.find(to_id);
	   if (to_node == NULL) {
		  cout << ">>> NOTE: Automatically creating node " << to_id
			   << "." << endl;
		  nodes.add(to_id);
		 }
      }
   else
	  cout << ">>> Creating pseudo arc" << endl;

   from_node = nodes.find(from_id);
   if (from_node == NULL) {
      cout << ">>> NOTE: Automatically creating node " << from_id 
		   << "." << endl;
      nodes.add(from_id);
      from_node = nodes.find(from_id);
     }
   from_node->addarc(to_id, arclabel);
}

Graph::delarc(int nodeid, int i) {
	Node* n;
   n = nodes.find(nodeid);
   if (n != NULL)
      n->delarc(i);
   else
      cout << ">>> Node with id " << nodeid << " unknown." << endl;
}

Graph::getRootId() {
   rootnode->getid();
}

Graph::SLprint(SLList<int>& list) {
	SLNode<int>*  n;
   n = (SLNode<int>*)list.first();
   while (n!=NULL) {
      cout << n->hd;
      list.next(n);
      if (n == NULL)
         cout << endl;
      else
         cout << ", ";
     }
}

int
Graph::findId(int nodeId, SLList<int>& list) {
	SLNode<int>*  n;
   n = (SLNode<int>*)list.first();
   while (n!=NULL) {
      if (n->hd == nodeId)
         return 1;
      else
         list.next(n);
     }
   return 0;
}

void
Graph :: do_dfs(int nodeId, SLList<int>& visited) {
	int destId;
	Node* cnode;
	Arc* arcPtr;

   if (!findId(nodeId, visited)) {
      visited.append(nodeId);
      cnode = nodes.find( nodeId );
      if (cnode != NULL) {
         arcPtr = cnode->firstArc();
         while (arcPtr != NULL) {
            destId = arcPtr->getdest();
            do_dfs(destId, visited);
            cnode->nextArc(arcPtr);
           }
        }
     }
}

void
Graph :: dfs(int nodeId) {
	SLList<int> visited;
   if (nodes.find(nodeId) == NULL)
      cout << ">>> No node with id " << nodeId << "." << endl;
   else {
      do_dfs(nodeId, visited);
      cout << " DFS : ";
      SLprint(visited);
     }
}

int
Graph::do_path(int fromNode, int toNode, SLList<int>& visited,
                SLList<int>& route) {
	int destId;
	Node* cnode;
	Arc* arcPtr;
	int check = 0;

   if (!findId(fromNode, visited)) {
      visited.append(fromNode);
      cnode = nodes.find(fromNode);
      if (cnode != NULL) {
         arcPtr = cnode->firstArc();
         while (arcPtr != NULL) {
            destId = arcPtr->getdest();
            if (destId == toNode) {
               route.prepend(destId);
               return 1;
              }
            check = do_path(destId, toNode, visited, route);
            if (check == 1) {
               route.prepend(destId);
               return 1;
              }
            cnode->nextArc(arcPtr);
           }
         return 0;
        }
     }
   else
      return 0;
}

void
Graph::path(int fromNode, int toNode) {
	SLList<int> visited;
	SLList<int> route;
	int check = 0;
   if (nodes.find(fromNode) == NULL)
      cout << ">>> No node with id " << fromNode << "." << endl;
   if (nodes.find(toNode) == NULL)
      cout << ">>> No node with id " << toNode << "." << endl;
   else if (fromNode == toNode)
      cout << "Path : " << fromNode << endl;
   else {
      check = do_path(fromNode, toNode, visited, route);
      if (check) {
         route.prepend(fromNode);
         cout << "Path : ";
         SLprint(route);
        }
      else
         cout << "No path from " << fromNode << " to " << toNode << "." << endl;
     }
}

void
Graph::unreach() {
	SLList<int> visited;
	Node* tmpNode;
   do_dfs(getRootId(), visited);
   cout << "Nodes unreachable from root : ";
   tmpNode = nodes.firstNode();
   if (tmpNode != NULL)
	   do {
		  if (!findId(tmpNode->getid(), visited)) {
			 cout << tmpNode->getid();
			 nodes.nextNode(tmpNode);
			 if (tmpNode != NULL)
				cout << ", ";
			}
		  else
			 nodes.nextNode(tmpNode);
		 } while (tmpNode != NULL);
   else
      cout << "None";		// for some reason this will NEVER print!
   cout << endl;
}

void
Graph::reach(int destId) {
	SLList<int> visited;
	SLList<int> route;
   if (nodes.find(destId) == NULL)
      cout << ">>> No node with id " << destId << "." << endl;
   else if (getRootId() == destId)
      cout << "Route to " << destId << " from root : " << destId << endl;
   else if (do_path(getRootId(), destId, visited, route)) {
      cout << "Route to " << destId << " from root : ";
      SLprint(route);
     }
   else
      cout << "No route to " << destId << " from the root exists." << endl;
}

int
Graph::do_cycle(int fromNode, int startNode,
                 SLList<int>& visited, SLList<int>& route) {
	int destId;
	Node* cnode;
	Arc* arcPtr;
	int check = 0;

   if (!findId(fromNode, visited)) {
      visited.append(fromNode);
      cnode = nodes.find(fromNode);
      if (cnode != NULL) {
         arcPtr = cnode->firstArc();
         while (arcPtr != NULL) {
            destId = arcPtr->getdest();
            check = do_cycle(destId, startNode, visited, route);
            if (check == 1) {
               route.prepend(destId);
               return 1;
              }
            cnode->nextArc(arcPtr);
           }
         return 0;
        }
     }
   else
      return 1;
}

void
Graph::cycle(int startNode) {
	SLList<int> visited;
	SLList<int> route;
	int check = 0;
   if (nodes.find(startNode) == NULL)
      cout << ">>> No node with id " << startNode << "." << endl;
   else {
      check = do_cycle(startNode, startNode, visited, route);
      if (check) {
         route.prepend(startNode);
         cout << "Cycle : ";
         SLprint(route);
        }
      else
         cout << "No cycle involving " << startNode << "." << endl;
     }
}

/*** Dag ***/

Dag::print() {
   cout << " Dag with id " << id << ":" << endl;
   return nodes.print();
}

Dag::addarc(int from_id, int to_id) {
	SLList<int> visited;
	SLList<int> route;
   if (from_id == to_id)
      cout << ">>> Cycle detected in acyclic graph; arc not added." << endl;
   else {
      Graph::addarc(from_id, to_id);
      if (do_path(to_id, from_id, visited, route)) {
         delarc(from_id, to_id);
         cout << ">>> Cycle detected in acyclic graph; arc not added." << endl;
        }
     }
}

Dag::addarc(int from_id, int to_id, String arclabel) {
	SLList<int> visited;
	SLList<int> route;
   if (from_id == to_id)
      cout << ">>> Cycle detected in acyclic graph; arc not added." << endl;
   else {
      Graph::addarc(from_id, to_id, arclabel);
      if (do_path(to_id, from_id, visited, route)) {
         delarc(from_id, to_id);
         cout << ">>> Cycle detected in acyclic graph; arc not added." << endl;
        }
     }
}
/*** Tree ***/

Tree::print() {
   cout << " Tree with id " << id << ":" << endl;
   return nodes.print();
}

Tree::findchildren (SLList<int>& children) {
	Node* tmpNode;
	Arc* tmpArc;
   tmpNode = nodes.firstNode();
   while (tmpNode != NULL) {
      tmpArc = tmpNode->firstArc();
      while (tmpArc != NULL) {
        if (!findId(tmpArc->getdest(), children))
           children.append(tmpArc->getdest());
        tmpNode->nextArc(tmpArc);
        }
      nodes.nextNode(tmpNode);
     }
}

Tree::addarc(int from_id, int to_id) {
	SLList<int> children;
   findchildren(children);
   if (findId(to_id, children))
      cout << ">>> Tree nodes may have only one parent." << endl;
   else
      Dag::addarc(from_id, to_id);
}

Tree::addarc(int from_id, int to_id, String arclabel) {
	SLList<int> children;
   findchildren(children);
   if (findId(to_id, children))
      cout << ">>> Tree nodes may have only one parent." << endl;
   else
      Dag::addarc(from_id, to_id, arclabel);
}

