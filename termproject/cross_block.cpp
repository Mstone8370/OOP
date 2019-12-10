#include "cross_block.h"

CrossBlock::CrossBlock(int x, Color c1, Color c2, Color c3) {
    this->min_x = x;
    this->min_y = 0;
    this->max_x = x + 2;
    this->max_y = 2;

    Block* b1 = new Block(c1, x+1, 2);
    Block* b2 = new Block(c2, x+2, 1);
    Block* b3 = new Block(c1, x+1, 1);
    Block* b4 = new Block(GREY, x, 1);
    Block* b5 = new Block(c3, x+1, 0);

    // this->v.push_back(b1);
    // this->v.push_back(b2);
    // this->v.push_back(b3);
    // this->v.push_back(b4);
    // this->v.push_back(b5);

    this->v.push_back(b5);
    this->v.push_back(b4);
    this->v.push_back(b3);
    this->v.push_back(b2);
    this->v.push_back(b1);
}

void CrossBlock::rotate() {
    
}