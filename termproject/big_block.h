#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

#include <algorithm>

#include "block.h"
#include "array_2d.h"

class BigBlock {
    protected:
    std::vector<Block*> v;
    int min_x, min_y, max_x, max_y;
    void update();

    public:
    virtual void rotate() = 0;
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    void down();
};

#endif