#include <string>

class Screen {
public:
    void dummy_fcn(pos height) {
        cursor = width * height;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    typedef std::string::size_type pos;
};