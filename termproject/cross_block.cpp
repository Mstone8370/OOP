#include "cross_block.h"

CrossBlock::CrossBlock(int x, Color c1, Color c2, Color c3, Color grey) {
    this->min_x = x;
    this->min_y = 0;
    this->max_x = x + 2;
    this->max_y = 2;

    Block* top;
    if(Array_2d::block_arr[0][x+1] != nullptr) top = new Block(UNABLE, x+1, 0);
    else top = new Block(c3, x+1, 0);

    Block* right;
    if(Array_2d::block_arr[1][x+2] != nullptr) right = new Block(UNABLE, x+2, 1);
    else right = new Block(c2, x+2, 1);

    Block* bottom;
    if(Array_2d::block_arr[2][x+1] != nullptr) bottom = new Block(UNABLE, x+1, 2);
    else bottom = new Block(c1, x+1, 2);

    Block* left;
    if(Array_2d::block_arr[1][x] != nullptr) left = new Block(UNABLE, x, 1);
    else left = new Block(grey, x, 1);

    Block* center;
    if(Array_2d::block_arr[1][x+1] != nullptr) center = new Block(UNABLE, x+1, 1);
    else center = new Block(c1, x+1, 1);
    

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