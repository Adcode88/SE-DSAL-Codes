#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    string name;
    Node *next;
    Node *down;

    Node( string n = "" ) {
        name = n;
        next = NULL;
        down = NULL;
    }
};

class Graph
{
    Node *head = NULL;

    void add( string NodeA, string NodeB ) {
        // If adjacency list is empty
        if( head == NULL ) {
            Node *node1 = new Node( NodeA );
            Node *node2 = new Node( NodeB );
            head = node1;
            node1->next = node2;
        }

        else {
            Node *curr = head;
            Node *prev = NULL;
            bool found = false;

            while( curr != NULL ) {

                // If NodeA is found
                if( curr->name == NodeA ) {
                    found = true;
                    Node *temp = curr;
                    while( temp->next != NULL ){
                        temp = temp->next;}
                    Node *newNode = new Node( NodeB );
                    temp->next = newNode;
                    break;
                }
                prev = curr;
                curr = curr->down;

            }

            // If NodeA is not found
            if(!found) {
                Node *newNode1 = new Node( NodeA );
                Node *newNode2 = new Node( NodeB );
                prev->down = newNode1;
                newNode1->next = newNode2;
            }
        }
    }

    public:

    void addNode( string NodeA, string NodeB ) {
        add( NodeA, NodeB );
        add( NodeB, NodeA );
    }

    void print() {
        Node *curr = head;
        while( curr != NULL ) {
            Node *temp = curr;
            while( temp != NULL ) {
                cout<< temp->name << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            curr = curr->down;
        }
    }

    void degrees(){
        Node *curr = head;
        while(curr != NULL){
            int c = 0;
            cout << curr->name << ": ";
            Node *temp = curr;
            while(temp != NULL){
                temp = temp->next;
                c++;
            }
            cout << c << endl;
            curr = curr->down;
        }
    }

    void BFS ( string node ) {
        queue<string> Queue;
        vector<string> visited;
        Queue.push( node );
        visited.push_back( node );
        while( true ) {

            if( !Queue.empty() ) {
                node = Queue.front();
                Queue.pop();
                cout<< node << " ";
            }
            else {
                cout<<endl;
                break;
            }

            Node *curr = head;
            bool found = false;
            while ( curr != nullptr ) {
                if( curr->name == node ) {
                    found = true;
                    Node *temp = curr->next;
                    while( temp != nullptr ){    
                        if( find( visited.begin(), visited.end(), temp->name ) == visited.end() ) {
                            visited.push_back( temp->name );
                            Queue.push( temp->name );
                        }
                        temp = temp->next;
                    }
                    break;
                }
                curr = curr->down;
            }
            if( !found ) {
                cout<< "Given node not in the graph" <<endl;
                return;
            }
        }
    }

    void DFS ( string node ) {
        stack<string> Stack;
        vector<string> visited;
        Stack.push( node );
        visited.push_back( node );
        while( true ) {
            if( !Stack.empty() ) {
                node = Stack.top();
                Stack.pop();
                cout<< node << " ";
            }
            else {
                cout<<endl;
                break;
            }

            Node *curr = head;
            bool found = false;
            while ( curr != nullptr ) {
                if( curr->name == node ) {
                    found = true;
                    Node *temp = curr->next;
                    while( temp != nullptr ) {
                        if( find( visited.begin(), visited.end(), temp->name ) == visited.end() ) {
                            Stack.push( temp->name );
                            visited.push_back( temp->name );
                        }
                        temp = temp->next;
                    }
                    break;
                }
                curr = curr->down;
            }
            if( !found ) {
                cout<< "Given node doesn't exist in the graph" <<endl;
                return;
            }
        }
    }
};

int main() {
    Graph g ; 
    g.addNode( "Katraj" , "PICT" ) ;
    g.addNode( "Bharti" , "Katraj" ) ; 
    g.addNode( "Bharti" , "PICT" ) ;
    g.addNode( "Katraj" , "SKNCOE" ) ; 
    g.addNode( "PICT" , "SKNCOE" ) ;
    g.addNode( "SKNCOE" , "Temple" ) ; 
    g.addNode( "Temple" , "Katraj" ) ; 
    g.addNode( "Temple" , "Kondhwa" ) ; 
    g.print();
    g.degrees();
    g.BFS( "Katraj" ) ; 
    g.DFS( "Katraj" ) ;
    return 0;
}