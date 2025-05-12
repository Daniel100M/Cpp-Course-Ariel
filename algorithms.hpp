#include "graph.hpp"

namespace graph {

    
    class Algorithms
    {
        public:
            Algorithms();
            ~Algorithms();
            graph::Graph* bfs(graph::Graph*, int);
            graph::Graph* dfs(graph::Graph*, int);
            graph::Graph* dijkstra(graph::Graph*, int);
            graph::Graph* prim(graph::Graph*, int);
            graph::Graph* kruskal(graph::Graph*, int);

    };


}
