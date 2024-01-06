#include "Position.hpp"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    Position p1 = Position(1, 2, 3);

    std::cout << p1 << std::endl;
    return 0;
}