/* Program Name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 12/4/2024
*  Purpose: This program outputs the nodes of a graph in a depth-first traversal.
*/

#include <iostream>
#include "graphType.h"

int main()
{
    // initialize variables
    // remember to put the maximum size of the graph as a parameter in the constructor and make it bigger than the number of vertices you plan on putting in
    // graph.txt contains 5 vertices, but I set MAX_SIZE to 7 just in case.
    graphType integerGraph(7);

    // create graph
    integerGraph.createGraph();

    // traverse graph depth-first
    integerGraph.depthFirstTraversal();

    // end program normally
    return 0;
}

