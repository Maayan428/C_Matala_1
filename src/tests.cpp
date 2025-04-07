
//maayan428@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/Graph.hpp"
#include "../src/Algorithms.hpp"
#include "../src/Stack.hpp"
#include "../src/Queue.hpp"
#include "../src/PriorityQueue.hpp"
#include "../src/UnionFind.hpp"

using namespace graph;

TEST_CASE("Graph basic operations") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    CHECK(g.hasEdge(0, 1));
    CHECK(g.hasEdge(1, 0)); // undirected
    CHECK(g.hasEdge(3, 4));
    CHECK_FALSE(g.hasEdge(0, 4));

    CHECK(g.getEdgeWeight(1, 2) == 20);

    g.removeEdge(1, 2);
    CHECK_FALSE(g.hasEdge(1, 2));
}

TEST_CASE("BFS builds correct tree") {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);

    Graph tree = Algorithms::bfs(g, 0);

    CHECK(tree.hasEdge(0, 1));
    CHECK(tree.hasEdge(0, 2));
    CHECK(tree.hasEdge(1, 3));
    CHECK(tree.hasEdge(2, 4));
    CHECK(tree.hasEdge(3, 5));
}

TEST_CASE("DFS builds correct tree") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 4, 1);

    Graph tree = Algorithms::dfs(g, 0);

    CHECK(tree.hasEdge(0, 1));
    bool has = tree.hasEdge(1, 2) || tree.hasEdge(1, 3);
    CHECK(has);
}

TEST_CASE("Dijkstra shortest path tree") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    Graph tree = Algorithms::dijkstra(g, 0);

    CHECK(tree.hasEdge(0, 1));
    CHECK(tree.hasEdge(1, 2));
    CHECK(tree.hasEdge(2, 3));
    CHECK(tree.hasEdge(3, 4));
    CHECK_FALSE(tree.hasEdge(0, 2)); // longer path should be skipped
}

TEST_CASE("Prim MST") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 3, 10);

    Graph mst = Algorithms::prim(g);

    CHECK(mst.hasEdge(0, 1));
    CHECK(mst.hasEdge(1, 2));
    CHECK(mst.hasEdge(2, 3));
    CHECK_FALSE(mst.hasEdge(0, 3));
}

TEST_CASE("Kruskal MST") {
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(0, 3, 5);

    Graph mst = Algorithms::kruskal(g);

    CHECK(mst.hasEdge(1, 2));
    CHECK(mst.hasEdge(2, 3));
    CHECK(mst.hasEdge(0, 1));
    CHECK_FALSE(mst.hasEdge(0, 3));
}

TEST_CASE("Stack basic usage") {
    Stack s;
    CHECK(s.isEmpty());

    s.push(5);
    s.push(10);
    CHECK(!s.isEmpty());
    CHECK(s.top() == 10);
    CHECK(s.pop() == 10);
    CHECK(s.pop() == 5);
    CHECK(s.isEmpty());
}

TEST_CASE("Queue basic usage") {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    CHECK(q.dequeue() == 1);
    CHECK(q.dequeue() == 2);
}

TEST_CASE("PriorityQueue behavior") {
    PriorityQueue pq;
    pq.enqueue(1, 3);
    pq.enqueue(2, 2);
    pq.enqueue(3, 1);

    CHECK(pq.dequeue() == 3);
    CHECK(pq.dequeue() == 2);
    CHECK(pq.dequeue() == 1);
}

TEST_CASE("PriorityQueue decrease key") {
    PriorityQueue pq;
    pq.enqueue(1, 5);
    pq.enqueue(2, 10);
    pq.decrease_key(2, 1);

    CHECK(pq.dequeue() == 2);
    CHECK(pq.dequeue() == 1);
}

TEST_CASE("UnionFind functionality") {
    UnionFind uf(4);
    uf.unite(0, 1);
    uf.unite(2, 3);
    CHECK(uf.find(0) == uf.find(1));
    CHECK(uf.find(2) == uf.find(3));
    CHECK(uf.find(0) != uf.find(2));
}

