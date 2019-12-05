#include <iostream>

#include "array_2d.h"

Block* Array_2d::block_arr[H][W] = { nullptr };

int main() {
    Array_2d* array_2d = new Array_2d();
    array_2d->print();
}