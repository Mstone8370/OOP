#include "array_2d.h"
#include "block.h"
#include "big_block.h"
#include "cross_block.h"
#include "fold_block.h"
#include "tree_block.h"

#define BLK_GEN_POS 1

Block* Array_2d::block_arr[H][W] = { nullptr };

Array_2d::Array_2d() {
    srand((unsigned int)time(0));

    while(true) {
        int random = rand() % 3;
        std::cout << random << std::endl;

        BigBlock* current_block;

        if(random == 0) {
            int c1, c2;
            this->choose_color(c1, c2);
            if(!this->can_make(FOLD)) break;
            current_block = new FoldBlock(BLK_GEN_POS, Color(c1), Color(c2));
        } else if(random == 1) {
            int c1, c2, c3;
            this->choose_color(c1, c2, c3);
            if(!this->can_make(CROSS)) break;
            current_block = new CrossBlock(BLK_GEN_POS, Color(c1), Color(c2), Color(c3));
        } else {
            int c1, c2;
            this->choose_color(c1, c2);
            if(!this->can_make(TREE)) break;
            current_block = new TreeBlock(BLK_GEN_POS, Color(c1), Color(c2));
        }

        while(true) {
            this->print();

            char c = getch();
            if(c == 'a') {
                current_block->left();
            } else if(c == 'd') {
                current_block->right();
            } else if(c == 's') {
                if(current_block->can_down()) {
                    current_block->down();
                } else {
                    delete(current_block);
                    this->down_blocks();
                    this->print();
                    break;
                }
            } else if(c == 'x') {
                delete(current_block);
                this->down_blocks();
                this->print();
                break;
            } else if(c == 'e') {
                current_block->rotate();
                this->print();
            } else {
                continue;
            }
        }
    }

    std::cout << "\nfin\n" << std::endl;
}

bool Array_2d::can_make(Type t) {
    switch(t) {
        case CROSS:
            for(int x = BLK_GEN_POS; x < BLK_GEN_POS+3; x++) {
                if(block_arr[2][x] != nullptr) {
                    return false;
                }
            }
            return true;
        case FOLD:
            for(int x = BLK_GEN_POS; x < BLK_GEN_POS+2; x++) {
                if(block_arr[1][x] != nullptr) {
                    return false;
                }
            }
            return true;
        case TREE:
            if(block_arr[2][BLK_GEN_POS] != nullptr) {
                return false;
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

void Array_2d::down_blocks() {
    for(int i = (H-1); i >= 0; i--) {
        for(int j = (W-1); j >= 0; j--) {
            Block* b = block_arr[i][j];
            if(b != nullptr) b->down_all();
        }
    }
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

void Array_2d::choose_color(int& c1, int& c2) {
    c1 = rand() % 3;
    c2 = rand() % 3;
    while(c1 == c2) c2 = rand() % 3;
    c1++;
    c2++;
}

void Array_2d::choose_color(int& c1, int& c2, int& c3) {
    c1 = rand() % 3;
    c2 = rand() % 3;
    c3 = rand() % 3;
    while(c1 == c2) c2 = rand() % 3;
    while(c1 == c3 || c2 == c3) c3 = rand() % 3;
    c1++;
    c2++;
    c3++;
}