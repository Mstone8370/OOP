#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

#include "block.h"

class BigBlock {
    private:

    public:
    void rotate();
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    void down();
    void down_all();
};

#endif