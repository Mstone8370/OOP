#include "block.h"

Block::Block(Color c, int x, int y) {
    this->color = c;
    this->x = x;
    this->y = y;
    this->set_location(x, y);
    Array_2d::update(this);
}

Color Block::get_color() { return this->color; }
int Block::get_x() { return this->x; }
int Block::get_y() { return this->y; }

void Block::set_location(int x, int y) {
    Array_2d::block_arr[this->y][this->x] = nullptr;
    this->x = x;
    this->y = y;
}

void Block::set_color(Color c) {
    this->color = c;
}

bool Block::can_left() {
    if(this->x > 0) {
        Block* left_block = Array_2d::block_arr[this->y][(this->x)-1];
        if(left_block == nullptr) {
            return true;
        }
    }

    return false;
}

bool Block::can_right() {
    if(this->x < (W-1)) {
        Block* right_block = Array_2d::block_arr[this->y][(this->x)+1];
        if(right_block == nullptr) {
            return true;
        }
    }

    return false;
}

bool Block::can_down() {
    if(this->y < (H-1)) {
        Block* down_block = Array_2d::block_arr[(this->y)+1][this->x];
        if(down_block == nullptr) {
            return true;
        }
    }

    return false;
}

void Block::left() {
    this->set_location((this->x)-1, this->y);
}

void Block::right() {
    this->set_location((this->x)+1, this->y);
}

void Block::down() {
    this->set_location(this->x, (this->y)+1);
}

void Block::down_all() {
    while(this->can_down()) {
        this->down();
    }
    Array_2d::update(this);
}

std::string Block::to_string() {
    switch(this->color) {
        case GREY:
            return "0";
        case RED:
            return "1";
        case GREEN:
            return "2";
        case BLUE:
            return "3";
        case EXPLOSION:
            return "X";
        default:
            return ".";
    }
    // return std::to_string(this->color);
}