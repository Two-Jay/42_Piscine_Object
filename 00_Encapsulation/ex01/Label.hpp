#ifndef LABEL_HPP
# define LABEL_HPP

#include <vector>
#include <string>

class Label {
    private :
        long min;
        long max;
        int print_width;
        std::vector<std::string> labels;
        Label();

    public :
        Label(long min, long max);
        Label(long min, long max, int additonal_space);
        ~Label();

        std::vector<std::string>::iterator begin();
        std::vector<std::string>::iterator end();
        std::vector<std::string>::reverse_iterator rbegin();
        std::vector<std::string>::reverse_iterator rend();

        long getMin() const;
        long getMax() const;
        long getPrintWidth() const;
};

#endif //LABEL_HPP