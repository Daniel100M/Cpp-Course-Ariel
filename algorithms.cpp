#include "algorithms.hpp"

namespace g = graph;

g::Algorithms::Algorithms(){
    std::cout << "Algorithms class constructor called.\n";
}

g::Algorithms::~Algorithms(){
    std::cout << "Algorithms class destructor called.\n";
}

g::Graph* g::Algorithms::bfs(g::Graph* gr, int rootNum){
    std::cout << "------ BFS ------\n";
    g::Graph* rootedTree = new Graph{gr->getSize()}; // BFS Output tree.
    Queue q{gr->getSize()};
    int parent[gr->getSize()]; // parent[i] = -1 indicates unvisited vertice.
    std::fill_n(parent, gr->getSize(), -1);
    int nodeNum = rootNum;
    int parentNum = -1; // Will be used for adding edges in 'rootedTree'.
    int len; // Amount of neighbours.
    
    parent[nodeNum] = 0; // Root is visited.
    while (nodeNum != -1){
        parentNum = nodeNum;
        std::cout << "Currently visiting: [" << nodeNum << "].\n";
        Node* temp = gr->getNeighbours()[nodeNum].getHead();
        len = gr->getNeighbours()[nodeNum].getLength();

        for (int i = 0; i < len; i++)
        {
            nodeNum = temp->getNum();
            std::cout << "Neighbour: " << nodeNum << std::endl;
            // Only if this node wasn't enqueued before.
            if (parent[nodeNum] == -1) {
                std::cout << "Wasn't visited! Enqueue.\n";
                q.enqueue(nodeNum);
                parent[nodeNum] = parentNum;
            }
            temp = temp->getNext(); // Moving to next neighbour.
        }
        std::cout << "Queue --> ";
        q.display();

        nodeNum = q.dequeue();
        rootedTree->addEdge(parent[nodeNum], nodeNum);
    }
    return rootedTree;
}

// -------------------------------------------------------------------------------
// DFS

void dfsVisit(int prev, int at, int* visited, g::LinkedList* neighbours, g::Graph* result){
    std::cout << "Visiting node: " << "[" << at << "].\n";
    if (visited[at] == 1) {return;}
    std::cout << "Wasn't visited!\n";
    if (prev != -1){ // Check if it's the root node.
        result->addEdge(prev, at); // Tree edge.
    }
    visited[at]++; // Ensuring this node won't be visited twice.
    g::Node* temp = neighbours[at].getHead();
    while (temp)
    {
        dfsVisit(at, temp->getNum(), visited, neighbours, result);
        temp = temp->getNext();
    }
    
}

g::Graph* g::Algorithms::dfs(g::Graph* gr, int rootNum){
    // g::LinkedList* white = new g::LinkedList();
    int n = gr->getSize();
    g::Graph* result = new Graph(n); 
    LinkedList* neighbours = gr->getNeighbours();
    int* visited = new int[n]; // 0 by default?
    //int counter[3] = {n, 0, 0};
    dfsVisit(-1, rootNum, visited, neighbours, result);
    
    // Ensuring that all graph nodes were visited:
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0){
            dfsVisit(-1, i, visited, neighbours, result);
        }
    }
    
    
    delete[] visited;
    return result;
}

// -------------------------------------------------------------------------------

g::Graph* g::Algorithms::dijkstra(g::Graph* gr, int rootNum){
    // return 2;
}
g::Graph* g::Algorithms::prim(g::Graph* gr, int rootNum){
    
}
g::Graph* g::Algorithms::kruskal(g::Graph* gr, int rootNum){

}