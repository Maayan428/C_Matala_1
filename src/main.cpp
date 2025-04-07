
//maayan428@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main() {
    try {
        Graph g(5);

        g.addEdge(0, 1, 2);
        g.addEdge(0, 4, 1);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 4);
        g.addEdge(3, 4, 5);

        std::cout << "Initial Graph:" << std::endl;
        g.print_graph();

        std::cout << "\nRemoving edge 1-3..." << std::endl;
        g.removeEdge(1, 3);
        g.print_graph();

        std::cout << "\nEdge 0-1 exists? " << (g.hasEdge(0, 1) ? "Yes" : "No") << std::endl;
        std::cout << "Weight of edge 0-1: " << g.getEdgeWeight(0, 1) << std::endl;

        std::cout << "\nBFS Tree from vertex 0:" << std::endl;
        Graph bfsTree = Algorithms::bfs(g, 0);
        bfsTree.print_graph();

        std::cout << "\nDFS Tree from vertex 0:" << std::endl;
        Graph dfsTree = Algorithms::dfs(g, 0);
        dfsTree.print_graph();

        std::cout << "\nDijkstra (SPT) from 0:" << std::endl;
        Graph spt = Algorithms::dijkstra(g, 0);
        spt.print_graph();

        std::cout << "\nPrim (MST):" << std::endl;
        Graph mst = Algorithms::prim(g);
        mst.print_graph();

        std::cout << "\nKruskal (MST):" << std::endl;
        Graph kruskalMST = Algorithms::kruskal(g);
        kruskalMST.print_graph();

    } catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
