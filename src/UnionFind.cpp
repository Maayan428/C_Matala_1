
//maayan428@gmail.com

#include "UnionFind.hpp"

namespace graph {

    UnionFind::UnionFind(int n) : size(n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    void UnionFind::unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    bool UnionFind::connected(int u, int v) {
        return find(u) == find(v);
    }

    int UnionFind::get_size() const {
        return size;
    }

}
