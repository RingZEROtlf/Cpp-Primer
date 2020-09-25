#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>

template <typename T>
class Screen
{
    friend std::istream& operator>>(std::istream&, Screen<T>&);
    friend std::ostream& operator<<(std::ostream&, Screen<T>&);
public:
    Screen() {}
    Screen(T width, T height) : width(width), height(height) {}

    T get_width() { return width; }
    T get_height() { return height; }

private:
    T width, height;
};

template <typename T>
std::istream& operator>>(std::istream &is, Screen<T> &screen)
{
    is >> screen.width >> screen.height;
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, Screen<T> &screen)
{
    os << screen.width << " " << screen.height;
    return os;
}

#endif