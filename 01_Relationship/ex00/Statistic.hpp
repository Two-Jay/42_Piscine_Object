#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <iostream>

class Statistic {
    private :
        int _level;
        int _exp;
        Statistic();

    public :
        Statistic(int level, int exp);
        Statistic(Statistic const & src);
        ~Statistic();
        Statistic & operator=(Statistic const & rhs);

        int getLevel() const;
        int getExp() const;
        
        void levelUp();
        void gainExp(int exp);
        
        friend std::ostream & operator<<(std::ostream & o, Statistic const & rhs);
};

#endif // STATISTIC_HPP