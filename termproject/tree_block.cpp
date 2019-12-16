#include "tree_block.h"

TreeBlock::TreeBlock(int x, Color c1, Color c2) {
    this->min_x = x;
    this->min_y = 0;
    this->max_x = x;
    this->max_y = 2;

    Block* b1;
    if(Array_2d::block_arr[0][x] != nullptr) b1 = new Block(UNABLE, x, 0);
    else b1 = new Block(c1, x, 0);

    Block* b2;
    if(Array_2d::block_arr[2][x] != nullptr) b2 = new Block(UNABLE, x, 2);
    else b2 = new Block(c1, x, 2);

    Block* center;
    if(Array_2d::block_arr[1][x] != nullptr) center = new Block(UNABLE, x, 1);
    else center = new Block(c2, x, 1);

    this->v.push_back(b1);
    this->v.push_back(b2);
    this->v.push_back(center);
}

bool TreeBlock::can_rotate() {
    if((this->min_x == this->max_x) && (0 < this->min_x && this->min_x < (W-1))) {
        Block* b1 = Array_2d::block_arr[min_y+1][min_x-1];
        Block* b2 = Array_2d::block_arr[min_y+1][min_x+1];
        if(b1 == nullptr && b2 == nullptr) return true;
    } else if((this->min_y == this->max_y) && (this->min_y < (H-1))) {
        Block* b1 = Array_2d::block_arr[min_y-1][min_x+1];
        Block* b2 = Array_2d::block_arr[min_y+1][min_x+1];
        if(b1 == nullptr && b2 == nullptr) return true;
    }

    return false;
}

void TreeBlock::rotate() {
    if(!this->can_rotate()) {
        return;
    }

    if(this->min_x == this->max_x) {
        move_block(min_x, min_y, min_x+1, min_y+1);
        move_block(min_x, max_y, min_x-1, min_y+1);
        this->min_x -= 1;
        this->max_x = this->min_x + 2;
        this->min_y += 1;
        this->max_y = this->min_y;
    } else if(this->min_y == this->max_y) {
        move_block(min_x, min_y, min_x+1, min_y-1);
        move_block(max_x, min_y, min_x+1, min_y+1);
        this->min_x += 1;
        this->max_x = this->min_x;
        this->min_y -= 1;
        this->max_y = this->min_y + 2;
    }
    
    this->update();
}

void TreeBlock::move_block(int x1, int y1, int x2, int y2) {
    Block* b = Array_2d::block_arr[y1][x1];
    if(b == nullptr) return;
    b->set_location(x2, y2);
}