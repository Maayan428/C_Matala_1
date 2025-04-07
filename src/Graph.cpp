
//maayan428@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

    Graph::Graph(int vertices) : numVertices(vertices) {
        if (vertices <= 0) {
            throw std::invalid_argument("Number of vertices must be positive.");
        }
        adjacency = new NeighborList[vertices];
    }

    Graph::~Graph() {
        delete[] adjacency;
    }

    void Graph::addEdge(int from, int to, int weight) {
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        adjacency[from].add(to, weight); // directed edge from -> to
        adjacency[to].add(from, weight); // directed edge to -> from (undirected behavior)
    }

    void Graph::removeEdge(int from, int to) {
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }
        bool removed1 = adjacency[from].remove(to);
        bool removed2 = adjacency[to].remove(from);

        if (!removed1 || !removed2) {
            throw std::runtime_error("Edge does not exist.");
        }
    }

    bool Graph::hasEdge(int from, int to) const {
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            return false;
        }
        return adjacency[from].contains(to);
    }

    int Graph::getEdgeWeight(int from, int to) const {
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }
        return adjacency[from].getWeight(to);
    }

    void Graph::print_graph() const {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            const NeighborList& list = adjacency[i];
            const Neighbor* neighbors = list.getAll();
            int size = list.getSize();
            if (neighbors == nullptr) continue;

            for (int j = 0; j < size; ++j) {
                std::cout << "-> (" << i << ", " << neighbors[j].id << ", " << neighbors[j].weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    const NeighborList& Graph::getNeighbors(int vertex) const {
        if (vertex < 0 || vertex >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }
        return adjacency[vertex];
    }

}
