#include <iostream>
#include "Vector2.hpp"
#include "Graph.hpp"
#include "Parser.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    try {
        std::string path = "resource/input.vec";
        Parser parser = Parser();
        parser.setPath(path);
        std::vector<Vector2> vecs = parser.parse();
        Graph graph = Graph(vecs);
        graph.save("./resource", "output", "txt");
        system("leaks ex01");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}