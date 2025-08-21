#ifndef CUBE_H
#define CUBE_H

#include "types.h"
#include "constants.h"

struct cube{
    //u8 stickers[x coordinate][y coordinate][z coordinate][direction (0 = x, 1 = y, 2 = z)];
    //LDB: x = y = z = 0
    u8 stickers[2][2][2][3];
};

void cube_constructor(struct cube* c){
    c->stickers[0][0][0][0] = ORANGE;
    c->stickers[0][0][1][0] = ORANGE;
    c->stickers[0][1][0][0] = ORANGE;
    c->stickers[0][1][1][0] = ORANGE;
    c->stickers[1][0][0][0] = RED;
    c->stickers[1][0][1][0] = RED;
    c->stickers[1][1][0][0] = RED;
    c->stickers[1][1][1][0] = RED;
    c->stickers[0][0][0][1] = YELLOW;
    c->stickers[0][0][1][1] = YELLOW;
    c->stickers[1][0][0][1] = YELLOW;
    c->stickers[1][0][1][1] = YELLOW;
    c->stickers[0][1][0][1] = WHITE;
    c->stickers[0][1][1][1] = WHITE;
    c->stickers[1][1][0][1] = WHITE;
    c->stickers[1][1][1][1] = WHITE;
    c->stickers[0][0][0][2] = BLUE;
    c->stickers[0][1][0][2] = BLUE;
    c->stickers[1][0][0][2] = BLUE;
    c->stickers[1][1][0][2] = BLUE;
    c->stickers[0][0][1][2] = GREEN;
    c->stickers[0][1][1][2] = GREEN;
    c->stickers[1][0][1][2] = GREEN;
    c->stickers[1][1][1][2] = GREEN;
}

void cube_move_R_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
}

void cube_move_R_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
}

void cube_move_R_double(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
}

void cube_move_U_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
}

void cube_move_U_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
}

void cube_move_U_double(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
}

void cube_move_F_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
}

void cube_move_F_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = temp;
}

void cube_move_F_double(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = temp;
}

void cube_move(struct cube* c, u64 m){
    switch(m){
        case 0: cube_move_R_normal(c); break;
        case 1: cube_move_R_inverse(c); break;
        case 2: cube_move_R_double(c); break;
        case 3: cube_move_U_normal(c); break;
        case 4: cube_move_U_inverse(c); break;
        case 5: cube_move_U_double(c); break;
        case 6: cube_move_F_normal(c); break;
        case 7: cube_move_F_inverse(c); break;
        case 8: cube_move_F_double(c); break;
    }
}

void cube_rotate_X_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = temp;
    temp = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = temp;
}

void cube_rotate_X_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = temp;
    temp = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate_X_double(struct cube* c){
    u8 temp;
    temp = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = temp;
    temp = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = temp;
    temp = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate_Y_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate_Y_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = temp;
}

void cube_rotate_Y_double(struct cube* c){
    u8 temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = temp;
    temp = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate_Z_normal(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = temp;
}

void cube_rotate_Z_inverse(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate_Z_double(struct cube* c){
    u8 temp;
    temp = c->stickers[0][0][1][1];
    c->stickers[0][0][1][1] = c->stickers[1][1][1][1];
    c->stickers[1][1][1][1] = temp;
    temp = c->stickers[0][0][1][2];
    c->stickers[0][0][1][2] = c->stickers[1][1][1][2];
    c->stickers[1][1][1][2] = temp;
    temp = c->stickers[0][1][1][0];
    c->stickers[0][1][1][0] = c->stickers[1][0][1][0];
    c->stickers[1][0][1][0] = temp;
    temp = c->stickers[0][1][1][1];
    c->stickers[0][1][1][1] = c->stickers[1][0][1][1];
    c->stickers[1][0][1][1] = temp;
    temp = c->stickers[0][1][1][2];
    c->stickers[0][1][1][2] = c->stickers[1][0][1][2];
    c->stickers[1][0][1][2] = temp;
    temp = c->stickers[1][1][1][0];
    c->stickers[1][1][1][0] = c->stickers[0][0][1][0];
    c->stickers[0][0][1][0] = temp;
    temp = c->stickers[0][0][0][1];
    c->stickers[0][0][0][1] = c->stickers[1][1][0][1];
    c->stickers[1][1][0][1] = temp;
    temp = c->stickers[0][0][0][2];
    c->stickers[0][0][0][2] = c->stickers[1][1][0][2];
    c->stickers[1][1][0][2] = temp;
    temp = c->stickers[0][1][0][0];
    c->stickers[0][1][0][0] = c->stickers[1][0][0][0];
    c->stickers[1][0][0][0] = temp;
    temp = c->stickers[0][1][0][1];
    c->stickers[0][1][0][1] = c->stickers[1][0][0][1];
    c->stickers[1][0][0][1] = temp;
    temp = c->stickers[0][1][0][2];
    c->stickers[0][1][0][2] = c->stickers[1][0][0][2];
    c->stickers[1][0][0][2] = temp;
    temp = c->stickers[1][1][0][0];
    c->stickers[1][1][0][0] = c->stickers[0][0][0][0];
    c->stickers[0][0][0][0] = temp;
}

void cube_rotate(struct cube* c, u64 r){ 
    switch(r){
        case 0: ; break;
        case 1: cube_rotate_Y_normal(c); break;
        case 2: cube_rotate_Y_inverse(c); break;
        case 3: cube_rotate_Y_double(c); break;
        case 4: cube_rotate_X_normal(c); break;
        case 5: cube_rotate_X_normal(c); cube_rotate_Z_normal(c); break;
        case 6: cube_rotate_X_normal(c); cube_rotate_Z_inverse(c); break;
        case 7: cube_rotate_X_normal(c); cube_rotate_Z_double(c); break;
        case 8: cube_rotate_X_inverse(c); break;
        case 9: cube_rotate_X_inverse(c); cube_rotate_Z_normal(c); break;
        case 10: cube_rotate_X_inverse(c); cube_rotate_Z_inverse(c); break;
        case 11: cube_rotate_X_inverse(c); cube_rotate_Z_double(c); break;
        case 12: cube_rotate_Z_normal(c); break;
        case 13: cube_rotate_Z_normal(c); cube_rotate_X_normal(c); break;
        case 14: cube_rotate_Z_normal(c); cube_rotate_X_inverse(c); break;
        case 15: cube_rotate_Z_normal(c); cube_rotate_X_double(c); break;
        case 16: cube_rotate_Z_inverse(c); break;
        case 17: cube_rotate_Z_inverse(c); cube_rotate_X_normal(c); break;
        case 18: cube_rotate_Z_inverse(c); cube_rotate_X_inverse(c); break;
        case 19: cube_rotate_Z_inverse(c); cube_rotate_X_double(c); break;
        case 20: cube_rotate_X_double(c); break;
        case 21: cube_rotate_X_double(c); cube_rotate_Y_normal(c); break;
        case 22: cube_rotate_Z_double(c); break;
        case 23: cube_rotate_Z_double(c); cube_rotate_Y_normal(c); break; 
    }
}

void cube_recolour(struct cube* c){ 
    u8 r[6]; 
    r[c->stickers[0][0][0][0]] = ORANGE;
    r[c->stickers[0][0][0][0] + 1 - (c->stickers[0][0][0][0] % 2) * 2] = RED;
    r[c->stickers[0][0][0][1]] = YELLOW;
    r[c->stickers[0][0][0][1] + 1 - (c->stickers[0][0][0][1] % 2) * 2] = WHITE;
    r[c->stickers[0][0][0][2]] = BLUE;
    r[c->stickers[0][0][0][2] + 1 - (c->stickers[0][0][0][2] % 2) * 2] = GREEN;
    for (u64 x = 0; x < 2; x++){
        for (u64 y = 0; y < 2; y++){
            for (u64 z = 0; z < 2; z++){
                for (u64 d = 0; d < 3; d++){
                    c->stickers[x][y][z][d] = r[c->stickers[x][y][z][d]];
                }
            }
        }
    }
}



#endif