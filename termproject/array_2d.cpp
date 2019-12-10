#include "array_2d.h"
#include "block.h"
#include "big_block.h"
#include "cross_block.h"

Block* Array_2d::block_arr[H][W] = { nullptr };

Array_2d::Array_2d() {
    // Block* block = new Block(BLUE, 1, 6);
    // block_arr[11][3] = new Block(RED, 3, 1);

    while(true) {

        BigBlock* current_block = new CrossBlock(1, RED, BLUE, GREEN);

        while(current_block != nullptr) {
            this->print();
            std::cout << current_block << std::endl;

            char c = getch();
            if(c == 'a') {
                current_block->left();
            } else if(c == 'd') {
                current_block->right();
            } else if(c == 's') {
                if(current_block->can_down()) {
                    current_block->down();
                } else {
                    std::vector<Block*> vec = current_block->get_block();
                    for(auto iter = vec.begin(); iter < vec.end(); iter++) {
                        (*iter)->down_all();
                    }
                    this->print();
                    delete(current_block);
                    break;
                }
            } else if(c == 'x') {
                current_block->down_all();
                std::vector<Block*> vec = current_block->get_block();
                for(auto iter = vec.begin(); iter < vec.end(); iter++) {
                    (*iter)->down_all();
                }
                this->print();
                delete(current_block);
                break;
            } else {
                continue;
            }
            
            // sleep(1);
        }
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

void Array_2d::update(Block* b) {
    int x = b->get_x();
    int y = b->get_y();
    block_arr[y][x] = b;
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