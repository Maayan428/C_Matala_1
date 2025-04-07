
//maayan428@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {

    class Algorithms {
    public:
        static const int INF;

        static Graph bfs(const Graph& graph, int start);
        static Graph dfs(const Graph& graph, int start);
        static Graph dijkstra(const Graph& graph, int start);
        static Graph prim(const Graph& graph);
        static Graph kruskal(const Graph& graph);
    };

}

#endif // ALGORITHMS_HPP
