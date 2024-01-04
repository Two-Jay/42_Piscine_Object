#ifndef IMAGE_HPP
# define IMAGE_HPP

class Image {
    protected:
        int _width;
        int _height;
        Image();

    public:
        Image(int width, int height);
        Image(Image const &src);
        ~Image();

        Image &operator=(Image const &rhs);

        int getWidth() const;
        int getHeight() const;
};

#endif //IMAGE_HPP