#include "Parser.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>

Parser::Parser(std::string &path) : _path(path) {
}

std::vector<Vector2> Parser::parse() {
    std::vector<Vector2> ret;
    return ret;
}
