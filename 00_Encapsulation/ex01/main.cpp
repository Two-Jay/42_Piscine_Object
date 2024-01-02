#include <iostream>
#include "Vector2.hpp"
#include "Parser.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    try {
        std::string path = argv[1];
        Parser parser = Parser(path);
        parser.parse();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}