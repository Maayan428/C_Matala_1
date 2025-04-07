
// maayan428@gmail.com

// This file implements fundamental graph algorithms:
// - Breadth-First Search (BFS)
// - Depth-First Search (DFS)
// - Dijkstra's algorithm (shortest paths)
// - Prim's algorithm (Minimum Spanning Tree)
// - Kruskal's algorithm (Minimum Spanning Tree)

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "PriorityQueue.hpp"
#include "Edge.hpp"
#include "UnionFind.hpp"
#include <iostream>


namespace graph {

    const int Algorithms::INF = 1e9;

    /**
     * Performs Breadth-First Search (BFS) starting from a given vertex.
     * Returns the BFS tree as a new Graph.
     */
    Graph Algorithms::bfs(const Graph& graph, int start) {
        int n = graph.getNumVertices();
        if (start < 0 || start >= n) return Graph(n);

        Graph tree(n);
        bool* visited = new bool[n];
        for (int i = 0; i < n; ++i) visited[i] = false;

        Queue q;
        q.enqueue(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int u = q.dequeue();

            std::cout << "Visiting node: " << u << std::endl;


            const NeighborList& neighbors = graph.getNeighbors(u);
            const Neighbor* all = neighbors.getAll();
            int size = neighbors.getSize();
            if (all == nullptr) continue;

            for (int i = 0; i < size; ++i) {

                std::cout << "  Checking neighbor: " << all[i].id << " with weight " << all[i].weight << std::endl;

                int v = all[i].id;
                int w = all[i].weight;
                if (!visited[v]) {
                    visited[v] = true;
                    q.enqueue(v);
                    tree.addEdge(u, v, w);
                }
            }
        }

        delete[] visited;
        return tree;
    }

    /**
     * Performs Depth-First Search (DFS) starting from a given vertex.
     * Returns the DFS tree as a new Graph.
     */
    Graph Algorithms::dfs(const Graph& graph, int start) {
        int n = graph.getNumVertices();
        if (start < 0 || start >= n) return Graph(n);

        Graph tree(n);
        bool* visited = new bool[n];
        for (int i = 0; i < n; ++i) visited[i] = false;

        Stack s;
        s.push(start);
        visited[start] = true;

        while (!s.isEmpty()) {
            int u = s.pop();

            const NeighborList& neighbors = graph.getNeighbors(u);
            const Neighbor* all = neighbors.getAll();
            int size = neighbors.getSize();
            if (all == nullptr) continue;

            for (int i = 0; i < size; ++i) {
                int v = all[i].id;
                int w = all[i].weight;
                if (!visited[v]) {
                    visited[v] = true;
                    tree.addEdge(u, v, w);
                    s.push(v);
                }
            }
        }

        delete[] visited;
        return tree;
    }

    /**
     * Computes the Shortest Path Tree (SPT) from a source using Dijkstra's algorithm.
     * Returns the SPT as a new Graph.
     */
    Graph Algorithms::dijkstra(const Graph& graph, int start) {
        int n = graph.getNumVertices();
        if (start < 0 || start >= n) return Graph(n);

        int* dist = new int[n];
        int* parent = new int[n];
        bool* visited = new bool[n];

        for (int i = 0; i < n; ++i) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[start] = 0;
        PriorityQueue pq;
        pq.enqueue(start, 0);

        while (!pq.is_empty()) {
            int u = pq.dequeue();
            if (visited[u]) continue;
            visited[u] = true;

            const NeighborList& neighbors = graph.getNeighbors(u);
            const Neighbor* all = neighbors.getAll();
            int size = neighbors.getSize();
            if (all == nullptr) continue;

            for (int i = 0; i < size; ++i) {
                int v = all[i].id;
                int weight = all[i].weight;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;

                    if (pq.contains(v))
                        pq.decrease_key(v, dist[v]);
                    else
                        pq.enqueue(v, dist[v]);
                }
            }
        }

        Graph spt(n);
        for (int v = 0; v < n; ++v) {
            if (parent[v] != -1) {
                int u = parent[v];
                int weight = graph.getEdgeWeight(u, v);
                spt.addEdge(u, v, weight);
            }
        }

        delete[] dist;
        delete[] parent;
        delete[] visited;
        return spt;
    }

    /**
     * Computes a Minimum Spanning Tree (MST) using Prim's algorithm.
     * Returns the MST as a new Graph.
     */
    Graph Algorithms::prim(const Graph& graph) {
        int n = graph.getNumVertices();
        if (n == 0) std::__throw_invalid_argument("Invalid Graph 0 vertix");

        int* key = new int[n];
        int* parent = new int[n];
        bool* in_mst = new bool[n];

        for (int i = 0; i < n; ++i) {
            key[i] = INF;
            parent[i] = -1;
            in_mst[i] = false;
        }

        key[0] = 0;
        PriorityQueue pq;
        pq.enqueue(0, 0);

        while (!pq.is_empty()) {
            int u = pq.dequeue();
            in_mst[u] = true;

            const NeighborList& neighbors = graph.getNeighbors(u);
            const Neighbor* all = neighbors.getAll();
            int size = neighbors.getSize();
            if (all == nullptr) continue;

            for (int i = 0; i < size; ++i) {
                int v = all[i].id;
                int weight = all[i].weight;

                if (!in_mst[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;

                    if (pq.contains(v))
                        pq.decrease_key(v, key[v]);
                    else
                        pq.enqueue(v, key[v]);
                }
            }
        }

        Graph mst(n);
        for (int v = 1; v < n; ++v) {
            if (parent[v] != -1) {
                int u = parent[v];
                int weight = graph.getEdgeWeight(u, v);
                mst.addEdge(u, v, weight);
            }
        }

        delete[] key;
        delete[] parent;
        delete[] in_mst;
        return mst;
    }

    /**
     * Computes a Minimum Spanning Tree (MST) using Kruskal's algorithm.
     * Returns the MST as a new Graph.
     */
    Graph Algorithms::kruskal(const Graph& graph) {
        int n = graph.getNumVertices();
        Edge* edges = new Edge[n * n];
        int edgeCount = 0;

        // Collect all unique edges (u < v to avoid duplicates in undirected graph)
        for (int u = 0; u < n; ++u) {
            const NeighborList& neighbors = graph.getNeighbors(u);
            const Neighbor* all = neighbors.getAll();
            int size = neighbors.getSize();
            if (all == nullptr) continue;

            for (int i = 0; i < size; ++i) {
                int v = all[i].id;
                int weight = all[i].weight;
                if (u < v) {
                    edges[edgeCount++] = Edge(u, v, weight);
                }
            }
        }

        // Sort edges by weight using bubble sort
        for (int i = 0; i < edgeCount - 1; ++i) {
            for (int j = 0; j < edgeCount - i - 1; ++j) {
                if (edges[j].getWeight() > edges[j + 1].getWeight()) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        UnionFind uf(n);
        Graph mst(n);
        int edge_added = 0;

        for (int i = 0; i < edgeCount && edge_added < n - 1; ++i) {
            int u = edges[i].getFrom();
            int v = edges[i].getTo();

            if (!uf.connected(u, v)) {
                uf.unite(u, v);
                mst.addEdge(u, v, edges[i].getWeight());
                edge_added++;
            }
        }

        delete[] edges;
        return mst;
    }

} // namespace graph
