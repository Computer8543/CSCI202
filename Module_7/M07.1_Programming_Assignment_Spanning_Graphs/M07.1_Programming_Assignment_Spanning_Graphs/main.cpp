/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 12/14/2024
*  Purpose: To implement Fleury's algorithm in a program with help from ChatGPT.
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

    // start Fleury Algorithm at 1 
    integerGraph.fleuryAlgorithm(1);

    // end program normally
    return 0;
}
