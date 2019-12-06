#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <iostream>
#include <unistd.h>

#include "block.h"
#include "color.h"

#define W 5
#define H 12

class Array_2d {
    private:
    int score;

    public:
    static Block* block_arr[H][W];
    Array_2d();
    int get_score();
    bool can_make();
    void delete_block(int x, int y);
    void print();
};

#endif