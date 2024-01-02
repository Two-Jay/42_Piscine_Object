#include <iostream>
#include "Vector2.hpp"
#include "Parser.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    try {
        std::string path = "resource/input.vec";
        Parser parser = Parser();
        parser.setPath(path);
        std::vector<Vector2> vecs = parser.parse();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}