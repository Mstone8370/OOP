#ifndef TREE_BLOCK_H
#define TREE_BLOCK_H

#include "big_block.h"

#include "color.h"

class TreeBlock: public BigBlock {
    private:
    void move_block(int x1, int y1, int x2, int y2);

    public:
    TreeBlock(int x, Color c1, Color c2);
    bool can_rotate();
    void rotate();
};

#endif