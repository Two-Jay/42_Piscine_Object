#include <vector>
#include <string>
#include <sstream>

// split string by ,
std::vector<std::string> split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

long ft_numlen(long num) {
    long ret = 0;
    if (num == 0) {
        return 1;
    }
    if (num < 0) {
        ret++;
    }
    while (num != 0) {
        num /= 10;
        ret++;
    }
    return ret;
}

long ft_expandrf(float num) {
    long ret = (long)num;
    if (num > 0 && num - ret > 0) {
        ret++;
    }
    else if (num < 0 && num - ret < 0) {
        ret--;
    }
    return ret;
}

long ft_roundf(float x) {
    if (x < 0.0)
        return static_cast<long>(x - 0.5);
    else
        return static_cast<long>(x + 0.5);
}

std::string ft_ltos(long n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}