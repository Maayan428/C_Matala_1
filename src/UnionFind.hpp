
//maayan428@gmail.com

#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

namespace graph {

    class UnionFind {
    private:
        int* parent;
        int* rank;
        int size;

    public:
        UnionFind(int n);
        ~UnionFind();

        int find(int u);
        void unite(int u, int v);
        bool connected(int u, int v);
        int get_size() const;

    };

}

#endif
