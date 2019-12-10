#ifndef CROSS_BLOCK_H
#define CROSS_BLOCK_H

#include "big_block.h"

#include "color.h"

class CrossBlock: public BigBlock {
    private:

    public:
    CrossBlock(int x, Color c1, Color c2, Color c3);
    void rotate();
};

#endif