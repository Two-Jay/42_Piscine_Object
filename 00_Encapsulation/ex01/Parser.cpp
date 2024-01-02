#include "Parser.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>

Parser::Parser(std::string &path) : _path(path) {
}

std::vector<Vector2> Parser::parse() {
    std::vector<Vector2> ret;
    // open file by path
    std::ifstream file(_path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }

    // read file line by line
    std::string line;
    while (std::getline(file, line)) {
        // parse line
        std::cout << line << std::endl;
    }
    return ret;
}
