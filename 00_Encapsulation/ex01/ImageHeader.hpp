#ifndef IMAGEHEADER_HPP
# define IMAGEHEADER_HPP

class ImageHeader {
    protected :
        int _width;
        int _height;
        ImageHeader();

    public:
        ImageHeader(int width, int height);
        ImageHeader(ImageHeader const &src);
        virtual ~ImageHeader();
        ImageHeader &operator=(ImageHeader const &rhs);

        int getWidth() const;
        int getHeight() const;

        virtual unsigned char *generateHeader() = 0;
};

#endif //IMAGEHEADER_HPP