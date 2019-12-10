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

void FoldBlock::rotate() {
    // TODO. 회전 범위 안에 BigBlock에 포함되지 않은 블록이 있으면 회전 불가능하게 만들기
    // 4개의 블록을 모두 검사해서 v에 포합되어있지 않은 블록이 있으면 바로 리턴
    int x, y;

    x = min_x;
    y = min_y;
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