#include "big_block.h"

bool BigBlock::can_left() {
    for(auto iter = this->v.begin(); iter < this->v.end(); iter++) {
        if( !((*iter)->can_left()) ) {
            return false;
        }
    }

    return true;
}

bool BigBlock::can_right() {
    for(auto iter = this->v.begin(); iter < this->v.end(); iter++) {
        if( !((*iter)->can_right()) ) {
            return false;
        }
    }

    return true;
}

bool BigBlock::can_down() {
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

}

void BigBlock::right() {

}

void BigBlock::down() {

}

void BigBlock::down_all() {
    while(this->can_down()) {
        this->down();
    }
}