#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <stdexcept>

namespace graph {

    // Represents an edge in the adjacency list
    struct Neighbor {
        int vertex; // Destination vertex
        int weight; // Weight of the edge
    };

    // Dynamic list of neighbors (manual dynamic array management)
    class NeighborList {
    private:
        Neighbor* neighbors;
        int size;
        int capacity;

        void resize(); // Expands the array when full

    public:
        NeighborList();
        ~NeighborList();
        
        void add(int vertex, int weight);
        bool remove(int vertex);
        void print() const;
        bool contains(int vertex) const;
    };

    // Graph class
    class Graph {
    private:
        int numVertices;
        NeighborList* adjacencyList;

    public:
        Graph(int vertices);
        ~Graph();

        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph() const;
    };

} // namespace graph

#endif // GRAPH_HPP