
//maayan428@gmail.com

#ifndef NEIGHBORLIST_HPP
#define NEIGHBORLIST_HPP

namespace graph {

    struct Neighbor {
        int id;
        int weight;
    };

    class NeighborList {
    private:
        Neighbor* neighbors;
        int capacity;
        int size;

        void resize();

    public:
        NeighborList();
        ~NeighborList();

        void add(int id, int weight);
        bool remove(int id);
        bool contains(int id) const;
        int getWeight(int id) const;
        void print() const;

        const Neighbor* getAll() const {
            if (size == 0 || neighbors == nullptr) return nullptr;
            return neighbors;
        }

        int getSize() const { return size; }
    };

} // namespace graph

#endif // NEIGHBORLIST_HPP
