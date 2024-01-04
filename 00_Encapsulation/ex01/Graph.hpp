#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <vector>
#include "Vector2.hpp"
#include "Label.hpp"

class Graph {
    private :
        std::vector<Vector2> _vecs;
        float x_min;
        float x_max;
        float y_min;
        float y_max;


    public :
        Graph();
        Graph(std::vector<Vector2> &vecs);
        ~Graph();

        std::vector<std::vector<char> > generateGraph(Label &xl, Label &yl) const;
        void add(Vector2 &vec);
        void remove(Vector2 &vec);
        friend std::ostream &operator<<(std::ostream &o, Graph const &rhs);
};

#endif //GRAPH_HPP
