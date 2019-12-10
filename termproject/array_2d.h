#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <iostream>
#include <unistd.h>
#include <vector>

#include "color.h"
#include "getch.h"

#define W 5
#define H 12

class Block;
class BigBlock;
class CrossBlock;
class FoldBlock;

enum Type {
    CROSS, FOLD, TREE
};

class Array_2d {
    private:
    int score;

    public:
    static Block* block_arr[H][W];
    Array_2d();
    bool can_make(Type t);
    int get_score();
    static void update(Block* b);
    void down_blocks();
    void delete_block(int x, int y);
    void print();
};

#endif