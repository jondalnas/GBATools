#pragma once
#include <string>

class Color {
public:
    static unsigned int hexTo8Col(std::string str);
    static unsigned short convert8to5(unsigned int col);
};