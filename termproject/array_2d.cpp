#include "array_2d.h"

Block* Array_2d::block_arr[H][W] = { nullptr };

Array_2d::Array_2d() {
    block_arr[0][3] = new Block(BLUE, 3, 0);
    block_arr[1][3] = new Block(RED, 3, 1);

    while(true) {
        this->print();
        for(int i = (H-1); i >= 0; i--) {
            for(int j = (W-1); j >= 0; j--) {
                Block* current_block = block_arr[i][j];
                if(current_block != nullptr) {
                    current_block->down();
                }
            }
        }
        sleep(1);
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
    std::system("clear");
    std::cout << "Score: " << this->score << std::endl;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            Block* current_block = block_arr[i][j];
            if(current_block == nullptr) {
                std::cout << " . ";
            } else {
                std::cout << " " << current_block->to_string() <<  " ";
            }
        }
        std::cout << std::endl;
    }
}