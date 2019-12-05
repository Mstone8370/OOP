#include "array_2d.h"


Array_2d::Array_2d() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            block_arr[i][j] = new Block(GREY);
        }
    }
}

int Array_2d::get_score() {
    return this->score;
}

bool Array_2d::can_make() {
    return false;
}

void Array_2d::delete_block(int x, int y) {

}

void Array_2d::print() {
    std::cout << "Score: " << this->score << std::endl;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            Block* current_block = block_arr[i][j];
            std::cout << current_block <<  "\t";
        }
        std::cout << std::endl;
    }
}