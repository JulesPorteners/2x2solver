#ifndef SOLVER_H
#define SOLVER_H

#include "types.h"
#include "constants.h"
#include "cube.h"
#include "tables.h"
#include "evaluation.h"

u64 rotations[2];
u64 rotations_size = 0;
u64 solution[MAX_MOVES];
u64 solution_size = 0;
u64 solution_value = INFINITY;

u64 update_move[MOVES][ANGLES] = {
	{0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6},
	{1, 4, 7, 1, 4, 7, 1, 4, 7, 1, 4, 7, 1, 4, 7, 1, 4, 7, 1, 4, 7, 1, 4, 7},
	{2, 5, 8, 2, 5, 8, 2, 5, 8, 2, 5, 8, 2, 5, 8, 2, 5, 8, 2, 5, 8, 2, 5, 8},
	{3, 6, 0, 6, 0, 3, 6, 0, 3, 3, 6, 0, 6, 0, 3, 3, 6, 0, 3, 6, 0, 6, 0, 3},
	{4, 7, 1, 7, 1, 4, 7, 1, 4, 4, 7, 1, 7, 1, 4, 4, 7, 1, 4, 7, 1, 7, 1, 4},
	{5, 8, 2, 8, 2, 5, 8, 2, 5, 5, 8, 2, 8, 2, 5, 5, 8, 2, 5, 8, 2, 8, 2, 5},
	{6, 0, 3, 3, 6, 0, 3, 6, 0, 6, 0, 3, 3, 6, 0, 6, 0, 3, 6, 0, 3, 3, 6, 0},
	{7, 1, 4, 4, 7, 1, 4, 7, 1, 7, 1, 4, 4, 7, 1, 7, 1, 4, 7, 1, 4, 4, 7, 1},
	{8, 2, 5, 5, 8, 2, 5, 8, 2, 8, 2, 5, 5, 8, 2, 8, 2, 5, 8, 2, 5, 5, 8, 2}
};

u64 update_LDB_piece[MOVES][ANGLES] = {
	{0, 1, 2, 3, 4, 11, 6, 19, 8, 9, 7, 23, 15, 13, 14, 21, 16, 5, 12, 22, 20, 18, 10, 17},
	{0, 1, 2, 3, 4, 17, 6, 10, 8, 9, 22, 5, 18, 13, 14, 12, 16, 23, 21, 7, 20, 15, 19, 11},
	{0, 1, 2, 3, 4, 23, 6, 22, 8, 9, 19, 17, 21, 13, 14, 18, 16, 11, 15, 10, 20, 12, 7, 5},
	{0, 1, 2, 10, 4, 5, 6, 7, 18, 8, 21, 11, 12, 17, 14, 15, 3, 22, 23, 19, 13, 16, 20, 9},
	{0, 1, 2, 16, 4, 5, 6, 7, 9, 23, 3, 11, 12, 20, 14, 15, 21, 13, 8, 19, 22, 10, 17, 18},
	{0, 1, 2, 21, 4, 5, 6, 7, 23, 18, 16, 11, 12, 22, 14, 15, 10, 20, 9, 19, 17, 3, 13, 8},
	{0, 1, 2, 3, 9, 5, 20, 7, 8, 22, 10, 6, 12, 13, 16, 4, 23, 17, 18, 14, 21, 11, 15, 19},
	{0, 1, 2, 3, 15, 5, 11, 7, 8, 4, 10, 21, 12, 13, 19, 22, 14, 17, 18, 23, 6, 20, 9, 16},
	{0, 1, 2, 3, 22, 5, 21, 7, 8, 15, 10, 20, 12, 13, 23, 9, 19, 17, 18, 16, 11, 6, 4, 14}
};

void rotate_algorithm(u64 input_alg[MAX_MOVES], u64 output_alg[MAX_MOVES], u64 alg_size, u64 rot[2], u64* rot_size, u64 ldb){
    switch (ldb){
        case 0: *rot_size = 0; break;
        case 1: rot[0] = ROTATION_X_INVERSE; rot[1] = ROTATION_Z_INVERSE; *rot_size = 2; break;
        case 2: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Y_NORMAL; *rot_size = 2; break;
        case 3: rot[0] = ROTATION_X_NORMAL; *rot_size = 1; break;
        case 4: rot[0] = ROTATION_X_DOUBLE; rot[1] = ROTATION_Z_INVERSE; *rot_size = 2; break;
        case 5: rot[0] = ROTATION_Y_INVERSE; *rot_size = 1; break;
        case 6: rot[0] = ROTATION_X_INVERSE; *rot_size = 1; break;
        case 7: rot[0] = ROTATION_Z_NORMAL; *rot_size = 1; break;
        case 8: rot[0] = ROTATION_X_DOUBLE; rot[1] = ROTATION_Y_NORMAL; *rot_size = 2; break;
        case 9: rot[0] = ROTATION_X_DOUBLE; *rot_size = 1; break;
        case 10: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Z_NORMAL; *rot_size = 2; break;
        case 11: rot[0] = ROTATION_X_INVERSE; rot[1] = ROTATION_Y_INVERSE; *rot_size = 2; break;
        case 12: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Y_DOUBLE; *rot_size = 2; break;
        case 13: rot[0] = ROTATION_Z_INVERSE; *rot_size = 1; break;
        case 14: rot[0] = ROTATION_Y_NORMAL; *rot_size = 1; break;
        case 15: rot[0] = ROTATION_Y_DOUBLE; *rot_size = 1; break;
        case 16: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Z_INVERSE; *rot_size = 2; break;
        case 17: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Y_INVERSE; *rot_size = 2; break;
        case 18: rot[0] = ROTATION_Z_DOUBLE; *rot_size = 1; break;
        case 19: rot[0] = ROTATION_X_INVERSE; rot[1] = ROTATION_Z_NORMAL; *rot_size = 2; break;
        case 20: rot[0] = ROTATION_X_INVERSE; rot[1] = ROTATION_Y_NORMAL; *rot_size = 2; break;
        case 21: rot[0] = ROTATION_X_NORMAL; rot[1] = ROTATION_Z_DOUBLE; *rot_size = 2; break;
        case 22: rot[0] = ROTATION_X_DOUBLE; rot[1] = ROTATION_Z_NORMAL; *rot_size = 2; break;
        case 23: rot[0] = ROTATION_X_DOUBLE; rot[1] = ROTATION_Y_INVERSE; *rot_size = 2; break;
    }
    for (u64 i = 0; i < alg_size; i++){
        output_alg[i] = update_move[input_alg[i]][ldb];
        ldb = update_LDB_piece[input_alg[i]][ldb];
    }
}

void found(u64 moves[MAX_MOVES], u64 moves_size){
    for (u64 ldb = 0; ldb < ANGLES; ldb++){  
        /*if (ldb != 0){
            continue;
        }*/
        u64 rotated_moves[MAX_MOVES];
        u64 rot[2];
        u64 rot_size;
        rotate_algorithm(moves, rotated_moves, moves_size, rot, &rot_size, ldb);
        u64 e = eval(rotated_moves, moves_size);
        if (e < solution_value){
            for (u64 i = 0; i < rot_size; i++){
                rotations[i] = rot[i];
            }
            rotations_size = rot_size;
            for (u64 i = 0; i < moves_size; i++){
                solution[i] = rotated_moves[i];
            }
            solution_size = moves_size;
            solution_value = e;
        }
    }
}

void search(u64 c, u64 d, u64 moves[MAX_MOVES], u64* moves_size){ 
    if (distances[c] == 0){ 
        found(moves, *moves_size);        
    }
    else{
        for (u64 m = 0; m < MOVES; m++){ 
            if ((*moves_size) > 0 && m / 3 == moves[(*moves_size) - 1] / 3){
                continue;
            }
            if (distances[graph[c][m]] < d){
                moves[*moves_size] = m;
                (*moves_size)++;
                search(graph[c][m], d - 1, moves, moves_size);
                (*moves_size)--;
            }
        }
    }
}

void solve(u64 c){
    u64 d = distances[c] + EXTRA_MOVES;
    u64 moves[MAX_MOVES];
    u64 moves_size = 0;
    search(c, d, moves, &moves_size);
}

#endif