#include "big_block.h"

bool BigBlock::can_left() {
    if(this->min_x == 0) return false;
    for(auto iter = this->v.begin(); iter < this->v.end(); iter++) {
        if( !((*iter)->can_left()) ) {
            int x = (*iter)->get_x();
            int y = (*iter)->get_y();
            Block* left_block = Array_2d::block_arr[y][x-1];
            if(std::find(this->v.begin(), this->v.end(), left_block) == this->v.end()) {
                return false;
            }
        }
    }

    return true;
}

bool BigBlock::can_right() {
    if(this->max_x == (W-1)) return false;
    for(auto iter = this->v.begin(); iter < this->v.end(); iter++) {
        if( !((*iter)->can_right()) ) {
            int x = (*iter)->get_x();
            int y = (*iter)->get_y();
            Block* right_block = Array_2d::block_arr[y][x+1];
            if(std::find(this->v.begin(), this->v.end(), right_block) == this->v.end()) {
                return false;
            }
        }
    }

    return true;
}

bool BigBlock::can_down() {
    if(this->max_y == (H-1)) return false;
    for(auto iter = this->v.begin(); iter < this->v.end(); iter++) {
        if( !((*iter)->can_down()) ) {
            int x = (*iter)->get_x();
            int y = (*iter)->get_y();
            Block* down_block = Array_2d::block_arr[y+1][x];
            if(std::find(this->v.begin(), this->v.end(), down_block) == this->v.end()) {
                return false;
            }
        }
    }

    return true;
}

void BigBlock::left() {
    if(this->can_left()) {
        for(auto iter = (this->v).begin(); iter < (this->v).end(); iter++) {
            (*iter)->left();
        }
    }
    for(auto iter = (this->v).begin(); iter < (this->v).end(); iter++) {
        Array_2d::update(*iter);
    }
}

void BigBlock::right() {
    if(this->can_right()) {
        for(auto iter = (this->v).begin(); iter < (this->v).end(); iter++) {
            (*iter)->right();
        }
    }
    for(auto iter = (this->v).begin(); iter < (this->v).end(); iter++) {
        Array_2d::update(*iter);
    }
}

void BigBlock::down() {
    if(this->can_down()) {
        for(auto iter = (this->v).begin(); iter < (this->v).end(); iter++) {
            (*iter)->down();
        }
    }
}

void BigBlock::down_all() {
    while(this->can_down()) {
        this->down();
    }
}

std::vector<Block*> BigBlock::get_block() {
    return this->v;
}