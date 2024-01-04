#ifndef PNGHEADER_HPP
# define PNGHEADER_HPP

#include "ImageHeader.hpp"

class PNGHeader : public ImageHeader {
    private:
        PNGHeader();

    public:
        PNGHeader(int width, int height);
        PNGHeader(PNGHeader const &src);
        virtual ~PNGHeader();

        PNGHeader &operator=(PNGHeader const &rhs);

        virtual unsigned char *generateHeader();
};

#endif //PNGHEADER_HPP