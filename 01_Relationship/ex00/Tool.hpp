#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Tool {
    protected :
        unsigned int _numberOfUse;
    
    public :
        Tool();
        Tool(Tool const & src);
        ~Tool();
        Tool & operator=(Tool const & rhs);

        unsigned int getNumberOfUse() const;
        void use();

        friend std::ostream & operator<<(std::ostream & o, Tool const & rhs);
};

#endif // TOOL_HPP