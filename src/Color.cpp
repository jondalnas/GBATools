#include "Color.h"

unsigned int Color::hexTo8Col(std::string str) {
    unsigned int res = 0;

    for (unsigned char i = 0; i < 6; i++) {
        char chr = str.c_str()[i];

        if ((unsigned char) (chr - '0') <= 9) chr -= '0';
        else if ((unsigned char) (chr - 'a') <= 6) chr -= 'a' - 10;
        else if ((unsigned char) (chr - 'A') <= 6) chr -= 'A' - 10;
        else return -1;

        res += chr << (4 * (5 - i));
    }

    return res;
}

unsigned short Color::convert8to5(unsigned int col) {
    unsigned char r = (col >> 16) & 0xff;
    unsigned char g = (col >> 8) & 0xff;
    unsigned char b = (col >> 0) & 0xff;

    r >>= 3;
    g >>= 3;
    b >>= 3;

    return r | (g << 5) | (b << 10);
}