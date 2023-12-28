#include "Parser.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>

Parser::Parser(std::string path) : _path(path) {
}

std::vector<Vector2> Parser::parse() {
    std::vector<Vector2> ret;
    std::ifstream file(this->_path);
    std::string line;
    std::string::size_type sz;
    float x;
    float y;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            x = std::stof(line, &sz);
            y = std::stof(line.substr(sz));
            ret.push_back(Vector2(x, y));
        }
        file.close();
    }
    return ret;
}
