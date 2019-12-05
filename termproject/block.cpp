#include "block.h"

Block::Block() {

}

Block::Block(Color c) {
    this->color = c;
}

Block::Block(Color c, int x, int y) {
    this->color = c;
    this->x = x;
    this->y = y;
}

Color Block::get_color() { return this->color; }
int Block::get_x() { return this->x; }
int Block::get_y() { return this->y; }

void Block::set_location(int x, int y) {
    this->x = x;
    this->y = y;
}

void Block::set_color(Color c) {
    this->color = c;
}