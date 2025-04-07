
//maayan428@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "NeighborList.hpp"
#include "Edge.hpp"

namespace graph {

    class Graph {
    private:
        int numVertices;
        NeighborList* adjacency;

    public:
        Graph(int vertices);
        ~Graph();

        void addEdge(int from, int to, int weight = 1);
        void removeEdge(int from, int to);
        bool hasEdge(int from, int to) const;
        int getEdgeWeight(int from, int to) const;

        void print_graph() const;

        int getNumVertices() const { return numVertices; }
        const NeighborList& getNeighbors(int vertex) const;
    };

} // namespace graph

#endif // GRAPH_HPP
