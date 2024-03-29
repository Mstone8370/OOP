#ifndef BLOCK_H
#define BLOCK_H

#include <string>

#include "array_2d.h"
#include "color.h"

class Block {
    private:
    Color color;
    int x, y;
    
    public:
    Block();
    Block(Color c, int x, int y);
    Color get_color();
    int get_x();
    int get_y();
    void set_location(int x, int y);
    void set_color(Color c);
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    void down();
    void down_all();
    std::string to_string();
};

#endif