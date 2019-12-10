#include "cross_block.h"

CrossBlock::CrossBlock(int x, Color c1, Color c2, Color c3) {
    this->min_x = x;
    this->min_y = 0;
    this->max_x = x + 2;
    this->max_y = 2;

    Block* top = new Block(c3, x+1, 0);
    Block* right = new Block(c2, x+2, 1);
    Block* bottom = new Block(c1, x+1, 2);
    Block* left = new Block(GREY, x, 1);
    Block* center = new Block(c1, x+1, 1);

    this->v.push_back(top);
    this->v.push_back(right);
    this->v.push_back(bottom);
    this->v.push_back(left);
    this->v.push_back(center);
}

void CrossBlock::rotate() {
    Color c0 = v[0]->get_color();
    Color c1 = v[1]->get_color();
    Color c2 = v[2]->get_color();
    Color c3 = v[3]->get_color();

    v[0]->set_color(c3);
    v[1]->set_color(c0);
    v[2]->set_color(c1);
    v[3]->set_color(c2);
}