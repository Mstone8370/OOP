#include "array_2d.h"
#include "block.h"
#include "big_block.h"
#include "cross_block.h"
#include "fold_block.h"
#include "tree_block.h"

#define BLK_GEN_POS (1)

Block* Array_2d::block_arr[H][W] = { nullptr };

Array_2d::Array_2d() {
    srand((unsigned int)time(0));
}

void Array_2d::run() {
    Type type;

    while(true) {
        int random = rand() % 3;

        BigBlock* current_block;

        if(random == 0) {
            type = FOLD;
            int c1, c2;
            this->choose_color(c1, c2);
            if(!this->can_make(type)) {
                current_block = new FoldBlock(BLK_GEN_POS, Color(c1), Color(c2));
                break;
            }
            current_block = new FoldBlock(BLK_GEN_POS, Color(c1), Color(c2));
        } else if(random == 1) {
            type = CROSS;
            int c1, c2, c3;
            this->choose_color(c1, c2, c3);
            if(!this->can_make(type)) {
                current_block = new CrossBlock(BLK_GEN_POS, Color(c1), Color(c2), Color(c3));
                break;
            }
            current_block = new CrossBlock(BLK_GEN_POS, Color(c1), Color(c2), Color(c3));
        } else {
            type = TREE;
            int c1, c2;
            this->choose_color(c1, c2);
            if(!this->can_make(type)) {
                current_block = new TreeBlock(BLK_GEN_POS+1, Color(c1), Color(c2));
                break;
            }
            current_block = new TreeBlock(BLK_GEN_POS+1, Color(c1), Color(c2));
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
        int s = 0;
        while(can_explosion()) {
            s++;

            usleep(300000);
            explosion(s);
            print(s);

            usleep(300000);
            clear_explosion();
            print(s);

            usleep(300000);
            down_blocks();
            print(s);
        }
    }

    print_end();
}

bool Array_2d::can_make(Type t) {
    int temp[3] = {1, 2, 1};    // for CROSS
    int index = 0;              // for CROSS
    switch(t) {
        case CROSS:
            for(int x = BLK_GEN_POS; x < BLK_GEN_POS+3; x++) {
                if(block_arr[temp[index++]][x] != nullptr) {
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
            if(block_arr[2][BLK_GEN_POS+1] != nullptr) {
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

bool Array_2d::can_explosion() {
    this->find_explosion();
    if(this->explosion_set.size() > 0) return true;
    return false;
}

void Array_2d::find_explosion() {
    for(int i = (H-1); i >= 0; i--) {
        for(int j = (W-1); j >= 0; j--) {
            Block* current_block = block_arr[i][j];
            if(current_block == nullptr) continue;
            if(std::find(explosion_set.begin(), explosion_set.end(), current_block) != explosion_set.end()) {
                continue;
            }
            std::set<Block*> s;
            find_same_color(current_block, s);

            int grey_count = 0;
            for(auto iter = s.begin(); iter != s.end(); iter++) {
                Color c = (*iter)->get_color();
                if(c == GREY) {
                    grey_count++;
                }
            }
            if((s.size()-grey_count) >= 4) {
                explosion_set.insert(s.begin(), s.end());
            }
        }
    }
}

void Array_2d::find_same_color(Block* b, std::set<Block*>& s) {
    int sequence[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; // { y, x }
    int x = b->get_x();
    int y = b->get_y();
    Color c = b->get_color();

    s.insert(b);
    for(int i = 0; i < 4; i++) {
        int next_x = x + sequence[i][1];
        int next_y = y + sequence[i][0];

        if((next_x < 0 || next_x >= W) || (next_y < 0 || next_y >= H)) continue;
        Block* neighbor = block_arr[next_y][next_x];

        if(neighbor == nullptr) continue;
        if(std::find(s.begin(), s.end(), neighbor) != s.end()) continue;

        Color neighbor_color = neighbor->get_color();
        if(neighbor_color == GREY) {
            s.insert(neighbor);
        } else if(c == neighbor_color) {
            find_same_color(neighbor, s);
        }
    }

    return;
}

void Array_2d::explosion(int s) {
    int next_score = score;
    for(auto iter = explosion_set.begin(); iter != explosion_set.end(); iter++) {
        int x = (*iter)->get_x();
        int y = (*iter)->get_y();
        block_arr[y][x]->set_color(EXPLOSION);
        next_score = score + s;
    }
    score = next_score;
}

void Array_2d::clear_explosion() {
    for(auto iter = explosion_set.begin(); iter != explosion_set.end(); iter++) {
        int x = (*iter)->get_x();
        int y = (*iter)->get_y();
        block_arr[y][x] = nullptr;
        delete(*iter);
    }
    explosion_set.erase(explosion_set.begin(), explosion_set.end());
}

void Array_2d::print(int bonus) {
    std::system("clear");
    std::cout << "Score: " << this->score;
    if(bonus < 1) std::cout << std::endl << std::endl;
    else if(bonus == 1) std::cout << "  +" << bonus << std::endl << std::endl;
    else std::cout << "  +" << bonus << "  combo!!" << std::endl << std::endl;

    // std::cout << "\033[0;47m W W W W W W W\033[0m" << std::endl;
    std::cout << "\033[0;47m              \033[0m" << std::endl;
    for(int i = 0; i < H; i++) {
        // std::cout << "\033[0;47m W\033[0m";
        std::cout << "\033[0;47m  \033[0m";
        for(int j = 0; j < W; j++) {
            Block* current_block = block_arr[i][j];
            if(current_block == nullptr) {
                std::cout << "  ";
            } else {
                std::cout << current_block->to_string() ;
            }
        }
        // std::cout << "\033[0;47m W\033[0m";
        std::cout << "\033[0;47m  \033[0m";
        std::cout << std::endl;
    }
    // std::cout << "\033[0;47m W W W W W W W\033[0m" << std::endl;
    std::cout << "\033[0;47m              \033[0m" << std::endl;
}

void Array_2d::print_end() {
    std::system("clear");
    std::cout << "Score: " << this->score << std::endl << std::endl;

    // std::cout << "\033[0;47m W W W W W W W\033[0m" << std::endl;
    std::cout << "\033[0;47m              \033[0m" << std::endl;
    for(int i = 0; i < H; i++) {
        // std::cout << "\033[0;47m W\033[0m";
        std::cout << "\033[0;47m  \033[0m";
        for(int j = 0; j < W; j++) {
            Block* current_block = block_arr[i][j];
            if(current_block == nullptr) {
                std::cout << "  ";
            } else {
                std::cout << current_block->to_string() ;
            }
        }
        // std::cout << "\033[0;47m W\033[0m";
        std::cout << "\033[0;47m  \033[0m";
        std::cout << std::endl;
    }
    // std::cout << "\033[0;47m W W W W W W W\033[0m" << std::endl;
    std::cout << "\033[0;47m              \033[0m" << std::endl << std::endl;
    std::cout << "==[ G A M E   O V E R ]==" << std::endl << std::endl;
    std::cout << "Score: " << this->score << std::endl << std::endl;
}