 
#ifndef H_graph
#define H_graph
  
#include <iostream>
#include <fstream>
#include <iomanip>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

using namespace std;

class graphType  
{
public:
    bool isEmpty() const;
      //Function to determine whether the graph is empty.
      //Postcondition: Returns true if the graph is empty;
      //               otherwise, returns false.

    void createGraph();
      //Function to create a graph.
      //Postcondition: The graph is created using the  
      //               adjacency list representation.

    void clearGraph();
      //Function to clear graph.
      //Postcondition: The memory occupied by each vertex 
      //               is deallocated.

    void printGraph() const;
      //Function to print graph.
      //Postcondition: The graph is printed.

    void depthFirstTraversal();
      //Function to perform the depth first traversal of
      //the entire graph.
      //Postcondition: The vertices of the graph are printed 
      //               using depth first traversal algorithm.

    void dftAtVertex(int vertex);
      //Function to perform the depth first traversal of 
      //the graph at a node specified by the parameter vertex.
      //Postcondition: Starting at vertex, the vertices are 
      //               printed using depth first traversal 
      //               algorithm.

    void breadthFirstTraversal();
      //Function to perform the breadth first traversal of
      //the entire graph.
      //Postcondition: The vertices of the graph are printed 
      //               using breadth first traversal algorithm.

    // Algorithm assumes the graph is connected and either Eulerian or semi-Eulerian.
    void fleuryAlgorithm(int startVertex);



    graphType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.

    ~graphType();
      //Destructor
      //The storage occupied by the vertices is deallocated.

protected:
    int maxSize;    //maximum number of vertices
    int gSize;      //current number of vertices
    unorderedLinkedList<int> *graph; //array to create 
                                     //adjacency lists 

private:
    void dft(int v, bool visited[]);
      //Function to perform the depth first traversal of 
      //the graph at a node specified by the parameter vertex.
      //This function is used by the public member functions
      //depthFirstTraversal and dftAtVertex.
      //Postcondition: Starting at vertex, the vertices are 
      //               printed using depth first traversal 
      //               algorithm.


    // Helper method to check if an edge is a bridge
    bool isBridge(unorderedLinkedList<int>* tempGraph, int u, int v);

    // Helper method to count connected components in the graph
    int countConnectedComponents(unorderedLinkedList<int>* tempGraph);

    // Depth-first exploration of a connected component
    void exploreComponent(unorderedLinkedList<int>* tempGraph, int vertex, bool* visited); 
};

bool graphType::isEmpty() const
{
    return (gSize == 0);
}

void graphType::createGraph() 
{
    ifstream infile;
    char fileName[50];

    int index;
    int vertex;
    int adjacentVertex;

    if (gSize != 0)	//if the graph is not empty, make it empty
        clearGraph();

    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    infile.open(fileName);

    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize;  //get the number of vertices

    for (index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } // end for

    infile.close();
} //end createGraph

void graphType::clearGraph()
{
    int index;

    for (index = 0; index < gSize; index++)
        graph[index].destroyList();

    gSize = 0;
} //end clearGraph


void graphType::printGraph() const
{
    int index;

    for (index = 0; index < gSize; index++)
    {
        cout << index << " ";
        graph[index].print();
        cout << endl;
    }

    cout << endl;
} //end printGraph

void graphType::depthFirstTraversal()
{
    bool *visited; //pointer to create the array to keep 
                   //track of the visited vertices
    visited = new bool[gSize];

    int index;

    for (index = 0; index < gSize; index++) 
        visited[index] = false;
	
        //For each vertex that is not visited, do a depth 
        //first traverssal
    for (index = 0; index < gSize; index++)	
        if (!visited[index]) 
            dft(index,visited);
    delete [] visited;
} //end depthFirstTraversal

void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " ";  //visit the vertex

    linkedListIterator<int> graphIt;

      //for each vertex adjacent to v
    for (graphIt = graph[v].begin(); graphIt != graph[v].end();
                                     ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited);
    } //end while
} //end dft

void graphType::dftAtVertex(int vertex)
{
    bool *visited;

    visited = new bool[gSize];

    for (int index = 0; index < gSize; index++)
        visited[index] = false;

    dft(vertex, visited);

    delete [] visited;
} // end dftAtVertex


void graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue;

    bool *visited;
    visited = new bool[gSize];

    for (int ind = 0; ind < gSize; ind++)
        visited[ind] = false;	//initialize the array 
                                //visited to false

    linkedListIterator<int> graphIt;

    for (int index = 0; index < gSize; index++)
        if (!visited[index])
        {
            queue.addQueue(index);
            visited[index] = true;
            cout << " " << index << " ";

            while (!queue.isEmptyQueue())
            {
                int u = queue.front();
                queue.deleteQueue();

                for (graphIt = graph[u].begin(); 
                     graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.addQueue(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            } //end while
        }
		
    delete [] visited;
} //end breadthFirstTraversal

    //Constructor
graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

    //Destructor
graphType::~graphType()
{
    clearGraph();
}

void graphType::fleuryAlgorithm(int startVertex)
{
    if (startVertex < 0 || startVertex >= gSize) {
        cout << "Invalid start vertex." << endl;
        return;
    }

    unorderedLinkedList<int> path;
    unorderedLinkedList<int>* tempGraph = new unorderedLinkedList<int>[gSize];

    // Create a temporary copy of the graph for edge manipulations
    for (int i = 0; i < gSize; i++) {
        linkedListIterator<int> graphIt = graph[i].begin();
        while (graphIt != graph[i].end()) {
            tempGraph[i].insertLast(*graphIt);
            ++graphIt;
        }
    }

    int current = startVertex;
    path.insertLast(current);

    while (!tempGraph[current].isEmptyList()) {
        linkedListIterator<int> edgeIt = tempGraph[current].begin();
        int next = *edgeIt;

        // Validate next index
        if (next < 0 || next >= gSize) {
            cerr << "Invalid vertex index: " << next << endl;
            exit(EXIT_FAILURE);
        }

        // Allow progress if no other choice is possible
        bool removedEdge = false;
        for (edgeIt = tempGraph[current].begin(); edgeIt != tempGraph[current].end(); ++edgeIt) {
            next = *edgeIt;

            if (next < 0 || next >= gSize) {
                cerr << "Invalid vertex index during iteration: " << next << endl;
                exit(EXIT_FAILURE);
            }

            if (tempGraph[current].length() == 1 || !isBridge(tempGraph, current, next)) {
                tempGraph[current].deleteNode(next);
                tempGraph[next].deleteNode(current);
                current = next;
                path.insertLast(current);
                removedEdge = true;
                break;
            }
        }

        // Fallback if all edges are bridges (to prevent infinite loop)
        if (!removedEdge) {
            next = *tempGraph[current].begin();

            // Validate next index again before fallback
            if (next < 0 || next >= gSize) {
                cerr << "Invalid vertex index in fallback: " << next << endl;
                exit(EXIT_FAILURE);
            }

            tempGraph[current].deleteNode(next);
            tempGraph[next].deleteNode(current);
            current = next;
            path.insertLast(current);
        }
    }



    cout << "Eulerian Path or Circuit: ";
    path.print();
    cout << endl;

    delete[] tempGraph;
}

// Helper method to check if an edge is a bridge
bool graphType::isBridge(unorderedLinkedList<int>* tempGraph, int u, int v)
{
    // Count connected components before removing the edge
    int initialComponents = countConnectedComponents(tempGraph);

    // Remove edge (u, v)
    tempGraph[u].deleteNode(v);
    tempGraph[v].deleteNode(u);

    // Count connected components after removing the edge
    int componentsAfter = countConnectedComponents(tempGraph);

    // Reinsert edge (u, v) back to graph
    tempGraph[u].insertLast(v);
    tempGraph[v].insertLast(u);

    // If removing the edge increases the number of components, it is a bridge
    return componentsAfter > initialComponents;
}

// Helper method to count connected components in the graph
int graphType::countConnectedComponents(unorderedLinkedList<int>* tempGraph)
{
    bool* visited = new bool[gSize]();
    int count = 0;

    for (int i = 0; i < gSize; i++) {
        if (!visited[i]) {
            exploreComponent(tempGraph, i, visited);
            count++;
        }
    }

    delete[] visited;
    return count;
}

// Depth-first exploration of a connected component
void graphType::exploreComponent(unorderedLinkedList<int>* tempGraph, int vertex, bool* visited)
{
    visited[vertex] = true;

    linkedListIterator<int> graphIt = tempGraph[vertex].begin();
    while (graphIt != tempGraph[vertex].end()) {
        int neighbor = *graphIt;
        if (!visited[neighbor]) {
            exploreComponent(tempGraph, neighbor, visited);
        }
        ++graphIt;
    }
}

#endif