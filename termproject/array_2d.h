#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <iostream>
#include <unistd.h>
#include <vector>
#include <set>
#include <ctime>

#include "color.h"
#include "getch.h"

#define W 5
#define H 12

class Block;
class BigBlock;
class CrossBlock;
class FoldBlock;
class TreeBlock;

enum Type {
    CROSS, FOLD, TREE
};

class Array_2d {
    private:
    int score;
    std::set<Block*> explosion_set;
    void find_explosion();
    void find_same_color(Block* b, std::set<Block*>& s);
    void clear_explosion();

    bool can_make(Type t);
    int get_score();
    void down_blocks();
    void delete_block(int x, int y);
    void choose_color(int& c1, int&c2);
    void choose_color(int& c1, int& c2, int& c3);
    bool can_explosion();
    void explosion(int s);
    void print(int bonus=0);
    void print_end(Type type);

    public:
    static Block* block_arr[H][W];
    Array_2d();
    void run();
    static void update(Block* b);
};

#endif