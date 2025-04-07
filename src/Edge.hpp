
//maayan428@gmail.com

#ifndef EDGE_HPP
#define EDGE_HPP

namespace graph {

    class Edge {
    private:
        int from;
        int to;
        int weight;

    public:

        Edge() : from(-1), to(-1), weight(0) {}

        Edge(int from, int to, int weight = 1)
                : from(from), to(to), weight(weight) {}

        int getFrom() const { return from; }
        int getTo() const { return to; }
        int getWeight() const { return weight; }
    };

} // namespace graph

#endif // EDGE_HPP
