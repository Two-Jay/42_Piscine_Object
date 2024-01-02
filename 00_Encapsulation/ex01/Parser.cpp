#include "Parser.hpp"
#include "utils.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>

Parser::Parser() {}

void Parser::setPath(std::string &path) {
    this->_path = path;
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
        std::vector<std::string> tokens = split(line, ',');
        if (tokens.size() != 2 || tokens[0].empty() || tokens[1].empty()) {
            throw std::runtime_error("Invalid file format : " + line);
        }
        // check token is float 
        try {
            float x = std::stof(tokens[0]);
            float y = std::stof(tokens[1]);
            ret.push_back(Vector2(x, y));
        } catch (std::exception &e) {
            throw std::runtime_error("Invalid file format : " + std::string(e.what()));
        }
    }
    return ret;
}
