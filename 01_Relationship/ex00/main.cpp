#include "Worker.hpp"
#include "Shovel.hpp"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    Position p1 = Position(1, 2, 3);
    Statistic s1 = Statistic(1, 2);
    Worker w1 = Worker(p1, s1);
    w1.moveBy(1, 1, 1);

    Shovel *shovel = new Shovel();
    std::cout << *shovel;

    w1.give(shovel);
    std::cout << w1;

    w1.work();
    std::cout << w1;

    w1.takeAway();
    std::cout << w1;
    
    delete shovel;
    return 0;
}