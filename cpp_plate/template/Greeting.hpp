# ifndef GREETING_HPP
# define GREETING_HPP

# include <iostream>

class Greeting {
public:
    Greeting() {};
    ~Greeting() {};
    void sayHello() {
        std::cout << "Hello, World!" << std::endl;
    }
};

# endif