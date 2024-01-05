#include "Label.hpp"
#include "utils.hpp"
#include "define.hpp"

Label::Label() {}

Label::Label(long min, long max) {
    this->min = min;
    this->max = max;
    // compare numberlength of min and max
    int flag = min < max * -1 ? -1 : 1;
    this->print_width = flag == -1 ? ft_numlen(min) : ft_numlen(max);
    if (this->print_width < MINIMUM_LABEL_RPINTWIDTH) {
        this->print_width += 1;
    }
    this->labels = std::vector<std::string>();
    for (long i = min; i <= max; i++) {
        std::string label = std::to_string(i);
        while (static_cast<long>(label.length()) < this->print_width) {
            label = " " + label;
        }
        this->labels.push_back(label);
    }
}

Label::Label(long min, long max, int additonal_space) {
    this->min = min;
    this->max = max;
    // compare numberlength of min and max
    int flag = min < max * -1 ? -1 : 1;
    this->print_width = flag == -1 ? ft_numlen(min) : ft_numlen(max);
    this->print_width += additonal_space;
    this->labels = std::vector<std::string>();
    for (long i = min; i <= max; i++) {
        std::string label = std::to_string(i);
        while (static_cast<long>(label.length()) < this->print_width) {
            label = " " + label;
        }
        this->labels.push_back(label);
    }
}

Label::~Label() {
    this->labels.clear();
}

std::vector<std::string>::iterator Label::begin() {
    return this->labels.begin();
}

std::vector<std::string>::reverse_iterator Label::rbegin() {
    return this->labels.rbegin();
}

std::vector<std::string>::iterator Label::end() {
    return this->labels.end();
}

std::vector<std::string>::reverse_iterator Label::rend() {
    return this->labels.rend();
}

long Label::getMin() const {
    return this->min;
}

long Label::getMax() const {
    return this->max;
}

long Label::getPrintWidth() const {
    return this->print_width;
}

int Label::getLabelSize() const {
    return this->labels.size();
}