#include "fold_block.h"

FoldBlock::FoldBlock(int x, Color c1, Color c2) {
    this->min_x = x;
    this->min_y = 0;
    this->max_x = x + 1;
    this->max_y = 1;

    Block* b1 = new Block(c1, x+1, 0);
    Block* b2 = new Block(c2, x+1, 1);
    Block* b3 = new Block(c2, x, 1);

    this->v.push_back(b1);
    this->v.push_back(b2);
    this->v.push_back(b3);
}

bool FoldBlock::can_rotate() {
    for(int i = min_y; i <= max_y; i++) {
        for(int j = min_x; j <= max_x; j++) {
            Block* b = Array_2d::block_arr[i][j];
            if(b == nullptr) continue;
            if(std::find((this->v).begin(), (this->v).end(), b) == (this->v).end()) {
                return false;
            }
        }
    }

    return true;
}

void FoldBlock::rotate() {
    if(!this->can_rotate()) {
        return;
    }

    int x, y;

    x = this->min_x;
    y = this->min_y;
    move_block(x, y, x+1, y);
    move_block(x, y+1, x, y);
    move_block(x+1, y+1, x, y+1);
    move_block(x+1, y, x+1, y+1);
    
    this->update();
}

void FoldBlock::move_block(int x1, int y1, int x2, int y2) {
    Block* b = Array_2d::block_arr[y1][x1];
    if(b == nullptr) return;
    b->set_location(x2, y2);
}