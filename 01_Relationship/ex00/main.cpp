#include "Position.hpp"
#include "Statistic.hpp"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    Position p1 = Position(1, 2, 3);
    Statistic s1 = Statistic(1, 2);

    std::cout << p1;
    std::cout << s1;
    return 0;
}