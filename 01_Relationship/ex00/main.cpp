#include "Worker.hpp"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    Position p1 = Position(1, 2, 3);
    Statistic s1 = Statistic(1, 2);

    std::cout << p1;
    std::cout << s1;

    Worker w1 = Worker(p1, s1);

    std::cout << w1;

    w1.moveBy(1, 1, 1);

    std::cout << w1;
    return 0;
}