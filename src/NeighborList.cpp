
//maayan428@gmail.com

#include "NeighborList.hpp"
#include <iostream>

namespace graph {

    NeighborList::NeighborList() : capacity(2), size(0) {
        neighbors = new Neighbor[capacity];
    }

    NeighborList::~NeighborList() {
        delete[] neighbors;
    }

    void NeighborList::resize() {
        capacity *= 2;
        Neighbor* newNeighbors = new Neighbor[capacity];
        for (int i = 0; i < size; ++i) {
            newNeighbors[i] = neighbors[i];
        }
        delete[] neighbors;
        neighbors = newNeighbors;
    }

    void NeighborList::add(int id, int weight) {
        if (contains(id)) return; // avoid duplicates

        if (size == capacity) {
            resize();
        }
        neighbors[size++] = { id, weight };
    }

    bool NeighborList::remove(int id) {
        for (int i = 0; i < size; ++i) {
            if (neighbors[i].id == id) {
                for (int j = i; j < size - 1; ++j) {
                    neighbors[j] = neighbors[j + 1];
                }
                size--;
                return true;
            }
        }
        return false;
    }

    bool NeighborList::contains(int id) const {
        for (int i = 0; i < size; ++i) {
            if (neighbors[i].id == id) return true;
        }
        return false;
    }

    int NeighborList::getWeight(int id) const {
        for (int i = 0; i < size; ++i) {
            if (neighbors[i].id == id) return neighbors[i].weight;
        }
        return -1; // not found
    }

    void NeighborList::print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << " -> " << neighbors[i].id << " (w=" << neighbors[i].weight << ")";
        }
    }



}
