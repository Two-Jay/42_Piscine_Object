#include "Parser.hpp"
#include "utils.hpp"

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <fstream>

Parser::Parser() {}

void Parser::setPath(std::string &path) {
    this->_path = path;
}

float Parser::getFloatValue(std::string s)  throw (std::runtime_error) {
    std::istringstream iss(s);
    float f;
    iss >> f; 
    if (iss.eof() && !iss.fail()) {
        return f;
    } else {
        throw std::runtime_error("Parser : Invalid float format " + s);
    }
}

std::vector<Vector2> Parser::parse() throw (std::runtime_error) {
    std::vector<Vector2> ret;

    std::ifstream file(_path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    // chech the file is empty
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        throw std::runtime_error("File is empty");
    }
    file.seekg(0, std::ios::beg);

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
            float x = this->getFloatValue(tokens[0]);
            float y = this->getFloatValue(tokens[1]);
            ret.push_back(Vector2(x, y));
        } catch (std::exception &e) {
            throw std::runtime_error("Invalid file format : " + std::string(e.what()));
        }
    }
    return ret;
}
