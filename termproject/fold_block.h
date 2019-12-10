#ifndef FOLD_BLOCK_H
#define FOLD_BLOCK_H

#include "big_block.h"

#include "color.h"

class FoldBlock: public BigBlock {
    private:
    void move_block(int x1, int y1, int x2, int y2);

    public:
    FoldBlock(int x, Color c1, Color c2);
    void rotate();
};

#endif