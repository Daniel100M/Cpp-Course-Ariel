#include "algorithms.hpp"

using namespace graph;

int const n = 8;

int main(){
    Graph* g = new Graph(n);
    //g->print_graph();
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(4, 2);
    g->addEdge(5, 2);
    g->addEdge(4, 5);
    g->addEdge(7, 6);
    //g->addEdge(4, 3);
    //g->removeEdge(2, 1);
    std::cout << "Graph:\n";
    g->print_graph();
    
    Algorithms alg{}; // Created on the stack (Destructor called automatically).
    
    Graph* dfsTree = alg.dfs(g, 0);
    std::cout << "DFS-Tree:\n";
    dfsTree->print_graph();

    Graph* bfsTree = alg.bfs(g, 0);
    std::cout << "BFS-Tree:\n";
    bfsTree->print_graph();

    delete dfsTree;
    delete bfsTree;
    delete g;
    //g->print_graph();
    // g.print_graph();
    //g.removeEdge(0, 1);
    //g.print_graph();
    return 0;
}