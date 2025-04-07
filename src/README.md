# Matala_1_C++

**Author:** Maayan Turgeman  
**Email:** maayan428@gmail.com

## Description

This project implements an undirected weighted graph using an **adjacency list** in C++.

It includes full implementations of the following graph algorithms:

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree (MST)
- Kruskal's MST using Union-Find

## Structure

The code is modular and well-documented, divided into the following classes:

- `Graph`: Manages vertices and edges using `NeighborList`.
- `Edge`: Represents a graph edge with `from`, `to`, and `weight`.
- `NeighborList`: Internal structure for storing neighbors of each vertex.
- `Queue`, `Stack`: Used in BFS and DFS respectively.
- `PriorityQueue`: Min-heap based, used in Dijkstra and Prim.
- `UnionFind`: Used in Kruskal's algorithm.
- `Algorithms`: Contains all algorithm implementations.

## File Overview

- `src/`: All class implementations and headers.
- `tests/`: Unit tests using `doctest`.
- `main.cpp`: Demonstration of the graph functionality and algorithms.
- `Makefile`: Build and test automation.

## Build & Run

### Compile & run main demo:
```bash
make Main
./Main
