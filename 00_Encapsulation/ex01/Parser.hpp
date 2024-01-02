#ifndef PARSER_HPP
# define PARSER_HPP

#include "Vector2.hpp"
#include <vector>

class Parser {
    private:
        std::string _path;

    public:
        Parser();
        void setPath(std::string &path);
        std::vector<Vector2> parse();
};

#endif //PARSER_HPP