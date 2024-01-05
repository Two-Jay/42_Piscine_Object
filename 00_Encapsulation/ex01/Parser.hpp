#ifndef PARSER_HPP
# define PARSER_HPP

#include "Vector2.hpp"
#include <vector>

class Parser {
    private:
        std::string _path;
        float getFloatValue(std::string s) throw (std::runtime_error);

    public:
        Parser();
        void setPath(std::string &path);
        std::vector<Vector2> parse() throw (std::runtime_error);
};

#endif //PARSER_HPP