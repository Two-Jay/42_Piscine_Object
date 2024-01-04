#ifndef PNG_HPP
# define PNG_HPP

#include "Image.hpp"
#include "PNGHeader.hpp"

class PNG : public Image {
    private:
        PNG();
        ImageHeader *_header;

    public:
        PNG(int width, int height);
        PNG(PNG const &src);
        ~PNG();

        PNG &operator=(PNG const &rhs);
};

#endif //PNG_HPP
