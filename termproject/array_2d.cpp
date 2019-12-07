#include "array_2d.h"
#include "block.h"
#include "big_block.h"

Block* Array_2d::block_arr[H][W] = { nullptr };

Array_2d::Array_2d() {
    // block_arr[0][3] = new Block(BLUE, 3, 0);
    // block_arr[1][3] = new Block(RED, 3, 1);

    Block* b1 = new Block(BLUE, 3, 0);
    Block* b2 = new Block(RED, 3,1);

    int i = 0;

    while(true) {
        i++;
        this->print();
        for(int i = (H-1); i >= 0; i--) {
            for(int j = (W-1); j >= 0; j--) {
                Block* current_block = block_arr[i][j];
                if(current_block != nullptr) {
                    current_block->down();
                }
            }
        }

        if(i == 11 || i == 13) {
            this->delete_block(3, 11);
        }
        sleep(1);
    }
}

bool Array_2d::can_make(Type t) {
    switch(t) {
        case CROSS:
            for(int x = 1; x < 4; x++) {
                if(block_arr[2][x] != nullptr) {
                    return false;
                }
            }
            return true;
        case FOLD:
            if(block_arr[2][2] != nullptr) {
                return false;
            }
            return true;
        case TREE:
            for(int x = 1; x < 3; x++) {
                if(block_arr[1][x] != nullptr) {
                    return false;
                }
            }
            return true;
        default:
            return false;
    }
}

int Array_2d::get_score() {
    return this->score;
}

void Array_2d::delete_block(int x, int y) {
    if((x < 0 || x >= W) || (y < 0 || y >= H)) {
        return;
    }
    Block* b = block_arr[y][x];
    if(b != nullptr) {
        delete(b);
        block_arr[y][x] = nullptr;
    }
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