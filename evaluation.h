#ifndef EVALUATION_H
#define EVALUATION_H

#include "types.h"
#include "constants.h"



///////////////////////




#define GRIPS 3
#define GRIP_THUMB_DOWN 0
#define GRIP_THUMB_FRONT 1
#define GRIP_THUMB_UP 2

#define TRICKS 11
#define TRICK_NONE 0
#define TRICK_LEFT_PINCH 1
#define TRICK_LEFT_INDEX 2
#define TRICK_LEFT_MIDDLE 3
#define TRICK_LEFT_DOUBLE 4
#define TRICK_LEFT_PUSH 5
#define TRICK_RIGHT_PINCH 6
#define TRICK_RIGHT_INDEX 7
#define TRICK_RIGHT_MIDDLE 8
#define TRICK_RIGHT_DOUBLE 9
#define TRICK_RIGHT_PUSH 10

#define COORDINATES (GRIPS * TRICKS * TRICKS)

struct coordinate{
    u64 grip;
    u64 trick1;
    u64 trick2;
};

struct coordinate number_to_coordinate(u64 n){
    struct coordinate result;
    result.trick2 = n % TRICKS;
    n /= TRICKS;
    result.trick1 = n % TRICKS;
    n /= TRICKS;
    result.grip = n;
    return result;
}

u64 coordinate_to_number(struct coordinate c){
    return TRICKS * TRICKS * c.grip + TRICKS * c.trick1 + c.trick2;
}
//11 * 11 * g + 11 * 0 + 0






struct edge{
    u64 to;
    u64 cost;
};

#define N COORDINATES

struct edge layer_move[9][N][10]; //printf to see what 10 should be prob 4 or 3
u64 layer_move_size[9][N];

void add_edge(u64 move, u64 i /*u64 grip_from, u64 trick_from*/, u64 grip, u64 trick1, u64 trick2, u64 cost){

    struct coordinate v;
    v.grip = grip;
    v.trick1 = trick1;
    v.trick2 = trick2;
    u64 j = coordinate_to_number(v);


    layer_move[move][i][layer_move_size[move][i]].to = j;
    layer_move[move][i][layer_move_size[move][i]].cost = cost;
    layer_move_size[move][i]++;
    if (layer_move_size[move][i] >= 4){
        printf("ERROR: layer_move_size[move][i] >= 4\n");
    }
}

u64 get_cost(u64 history1, u64 history2, u64 next){
    u64 result;




    if (history2 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_MIDDLE){
        result = 175;
    }
    else if (history2 == TRICK_LEFT_PINCH && next == TRICK_LEFT_MIDDLE){
        result = 175;
    }
    else if (history2 != TRICK_NONE){
        result = 500;
    } 
    else{
        if (history1 == TRICK_NONE && next == TRICK_RIGHT_PINCH){ result = NONE_NONE_PINCH; }
        else if (history1 == TRICK_NONE && next == TRICK_RIGHT_INDEX){ result = NONE_NONE_INDEX; }
        else if (history1 == TRICK_NONE && next == TRICK_RIGHT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (history1 == TRICK_NONE && next == TRICK_RIGHT_PUSH){ result = NONE_NONE_PUSH; }
        else if (history1 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_PINCH){ result = PINCH_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_INDEX){ result = PINCH_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_MIDDLE){ result = PINCH_NONE_MIDDLE; } 
        else if (history1 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_DOUBLE){ result = PINCH_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_PUSH){ result = PINCH_NONE_PUSH; }
        else if (history1 == TRICK_RIGHT_INDEX && next == TRICK_RIGHT_PINCH){ result = INDEX_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_INDEX && next == TRICK_RIGHT_INDEX){ result = INDEX_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_INDEX && next == TRICK_RIGHT_MIDDLE){ result = INDEX_NONE_MIDDLE; } 
        else if (history1 == TRICK_RIGHT_INDEX && next == TRICK_RIGHT_DOUBLE){ result = INDEX_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_INDEX && next == TRICK_RIGHT_PUSH){ result = INDEX_NONE_PUSH; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_PINCH){ result = MIDDLE_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_INDEX){ result = MIDDLE_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_DOUBLE){ result = MIDDLE_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_PUSH){ result = MIDDLE_NONE_PUSH; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_PINCH){ result = DOUBLE_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_INDEX){ result = DOUBLE_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_DOUBLE){ result = DOUBLE_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_PUSH){ result = DOUBLE_NONE_PUSH; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_PINCH){ result = PUSH_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_INDEX){ result = PUSH_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_DOUBLE){ result = PUSH_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_PUSH){ result = PUSH_NONE_PUSH; }

        else if (history1 == TRICK_NONE && next == TRICK_LEFT_PINCH){ result = NONE_NONE_PINCH; }
        else if (history1 == TRICK_NONE && next == TRICK_LEFT_INDEX){ result = NONE_NONE_INDEX; }
        else if (history1 == TRICK_NONE && next == TRICK_LEFT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (history1 == TRICK_NONE && next == TRICK_LEFT_PUSH){ result = NONE_NONE_PUSH; }
        else if (history1 == TRICK_LEFT_PINCH && next == TRICK_LEFT_PINCH){ result = PINCH_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_PINCH && next == TRICK_LEFT_INDEX){ result = PINCH_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_PINCH && next == TRICK_LEFT_MIDDLE){ result = PINCH_NONE_MIDDLE; } 
        else if (history1 == TRICK_LEFT_PINCH && next == TRICK_LEFT_DOUBLE){ result = PINCH_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_PINCH && next == TRICK_LEFT_PUSH){ result = PINCH_NONE_PUSH; }
        else if (history1 == TRICK_LEFT_INDEX && next == TRICK_LEFT_PINCH){ result = INDEX_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_INDEX && next == TRICK_LEFT_INDEX){ result = INDEX_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_INDEX && next == TRICK_LEFT_MIDDLE){ result = INDEX_NONE_MIDDLE; } 
        else if (history1 == TRICK_LEFT_INDEX && next == TRICK_LEFT_DOUBLE){ result = INDEX_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_INDEX && next == TRICK_LEFT_PUSH){ result = INDEX_NONE_PUSH; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_PINCH){ result = MIDDLE_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_INDEX){ result = MIDDLE_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_DOUBLE){ result = MIDDLE_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_PUSH){ result = MIDDLE_NONE_PUSH; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_PINCH){ result = DOUBLE_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_INDEX){ result = DOUBLE_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_DOUBLE){ result = DOUBLE_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_PUSH){ result = DOUBLE_NONE_PUSH; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_PINCH){ result = PUSH_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_INDEX){ result = PUSH_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_DOUBLE){ result = PUSH_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_PUSH){ result = PUSH_NONE_PUSH; }

        else if (next == TRICK_LEFT_PINCH){ result = NONE_NONE_PINCH; }
        else if (next == TRICK_LEFT_INDEX){ result = NONE_NONE_INDEX; }
        else if (next == TRICK_LEFT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (next == TRICK_LEFT_PUSH){ result = NONE_NONE_PUSH; }  

        else if (next == TRICK_RIGHT_PINCH){ result = NONE_NONE_PINCH; }
        else if (next == TRICK_RIGHT_INDEX){ result = NONE_NONE_INDEX; }
        else if (next == TRICK_RIGHT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (next == TRICK_RIGHT_PUSH){ result = NONE_NONE_PUSH; } 
        else{
            result = 0;
            printf("also burn the house down\n");
        }
    }
    return result;
}

void init_layers1(){
    for (u64 m = 0; m < MOVES; m++){
        for (u64 i = 0; i < COORDINATES; i++){
            struct coordinate u = number_to_coordinate(i);
            u64 cost;
            if (m == MOVE_R_NORMAL){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_NONE, QUARTER_WRIST); 
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    add_edge(m, i, GRIP_THUMB_UP, u.trick2, TRICK_NONE, QUARTER_WRIST); 
                }
                else if (u.grip == GRIP_THUMB_UP){ 
                    ; 
                }
            }
            else if (m == MOVE_R_INVERSE){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    ; 
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_NONE, QUARTER_WRIST); 
                }
                else if (u.grip == GRIP_THUMB_UP){ 
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_NONE, QUARTER_WRIST);
                }
            }
            else if (m == MOVE_R_DOUBLE){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    add_edge(m, i, GRIP_THUMB_UP, u.trick2, TRICK_NONE, HALF_WRIST); 
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    ; 
                }
                else if (u.grip == GRIP_THUMB_UP){ 
                    add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_NONE, HALF_WRIST); 
                }
            }
            else if (m == MOVE_U_NORMAL){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PUSH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PUSH)); 
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PUSH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PUSH));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_INDEX, get_cost(u.trick1, u.trick2, TRICK_RIGHT_INDEX));
                    if (u.trick1 == TRICK_RIGHT_INDEX || u.trick2 == TRICK_RIGHT_PINCH){
                        add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_RIGHT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PUSH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PUSH));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PINCH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PINCH));
                }
            }
            else if (m == MOVE_U_INVERSE){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_INDEX, get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    if (u.trick1 == TRICK_LEFT_INDEX || u.trick2 == TRICK_LEFT_PINCH){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_FRONT){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_INDEX, get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PUSH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PUSH));
                    if (u.trick1 == TRICK_LEFT_INDEX || u.trick2 == TRICK_LEFT_PINCH){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_INDEX, get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    if (u.trick1 == TRICK_LEFT_INDEX){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
            }
            else if (m == MOVE_U_DOUBLE){
                if (u.grip == GRIP_THUMB_DOWN){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_RIGHT_DOUBLE));
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                }
            }  
            else if (m == MOVE_F_NORMAL){
                if (u.grip == GRIP_THUMB_DOWN){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_INDEX, get_cost(u.trick1, u.trick2, TRICK_RIGHT_INDEX));
                    if (u.trick1 == TRICK_RIGHT_INDEX){
                        add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_RIGHT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_FRONT){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PINCH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PINCH));
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    ;
                }
            }
            else if (m == MOVE_F_INVERSE){
                if (u.grip == GRIP_THUMB_DOWN){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PINCH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PINCH));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PUSH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PUSH));
                }
                else if (u.grip == GRIP_THUMB_FRONT){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PINCH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PINCH));
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    ;
                }
            }
            else if (m == MOVE_F_DOUBLE){
                if (u.grip == GRIP_THUMB_DOWN){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_RIGHT_DOUBLE));
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    ;
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    ;
                }
            } 
        }
    }
}

u64 eval(u64 moves[MAX_MOVES], u64 moves_size){
    u64 distances_even[N]; 
    u64 distances_odd[N]; 
    for (u64 i = 0; i < N; i++){
        distances_even[i] = INFINITY;
    }
    
    /*
    distances_even[0] = 100;
    distances_even[121] = 0; 
    distances_even[242] = 100;   
*/
    /*
    init distances_odd instead as if we had just done one move
    
    
        TD      TF      TU
    R 
    R' 
    R2 
    U   -       1       br
    U'  gr      1       gr
    U2  gr      2       gr
    F   br      1       -
    F'  gr      1       -
    F2  br      -       -


    */
    
/*
    if (moves_size > 0){
        struct coordinate x;
        x.trick1 = TRICK_NONE;

        if (moves[0] == MOVE_R_NORMAL){
            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = QUARTER_WRIST + BAD_REGRIP;

            x.grip = GRIP_THUMB_UP;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = QUARTER_WRIST;
        }
        else if (moves[0] == MOVE_R_INVERSE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = QUARTER_WRIST;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = QUARTER_WRIST + BAD_REGRIP;
        }
        else if (moves[0] == MOVE_R_DOUBLE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = HALF_WRIST + BAD_REGRIP;

            x.grip = GRIP_THUMB_UP;
            x.trick2 = TRICK_NONE;
            distances_odd[coordinate_to_number(x)] = HALF_WRIST + BAD_REGRIP;
        }
        else if (moves[0] == MOVE_U_NORMAL){
            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_RIGHT_INDEX;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX;

            x.grip = GRIP_THUMB_UP;
            x.trick2 = TRICK_RIGHT_PINCH;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + BAD_REGRIP;
        }
        else if (moves[0] == MOVE_U_INVERSE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_LEFT_INDEX;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + GOOD_REGRIP;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_LEFT_INDEX;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX;

            x.grip = GRIP_THUMB_UP;
            x.trick2 = TRICK_LEFT_INDEX;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + GOOD_REGRIP;
        }
        else if (moves[0] == MOVE_U_DOUBLE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_LEFT_DOUBLE;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + GOOD_REGRIP;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_LEFT_DOUBLE;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_RIGHT_DOUBLE;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE;

            x.grip = GRIP_THUMB_UP;
            x.trick2 = TRICK_LEFT_DOUBLE;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + GOOD_REGRIP;
        }
        else if (moves[0] == MOVE_F_NORMAL){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_RIGHT_INDEX;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + BAD_REGRIP;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_RIGHT_PINCH;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH;
        }
        else if (moves[0] == MOVE_F_INVERSE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_LEFT_PINCH;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + GOOD_REGRIP;

            x.grip = GRIP_THUMB_FRONT;
            x.trick2 = TRICK_LEFT_PINCH;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + GOOD_REGRIP;
        }
        else if (moves[0] == MOVE_F_DOUBLE){
            x.grip = GRIP_THUMB_DOWN;
            x.trick2 = TRICK_RIGHT_DOUBLE;
            distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + BAD_REGRIP;
        }   
    }
    */
    for (u64 m = 0; m < moves_size; m++){
        /*if (m == 0){
            continue; //this might cause some ub at the bottom 
        }*/
        if (m % 2 == 0){
            for (u64 i = 0; i < N; i++){
                distances_odd[i] = INFINITY;
            }
            if (m == 0){
                if (moves_size > 0){
                    struct coordinate x;
                    x.trick1 = TRICK_NONE;

                    if (moves[0] == MOVE_R_NORMAL){
                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = QUARTER_WRIST + BAD_REGRIP;

                        x.grip = GRIP_THUMB_UP;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = QUARTER_WRIST;
                    }
                    else if (moves[0] == MOVE_R_INVERSE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = QUARTER_WRIST;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = QUARTER_WRIST + BAD_REGRIP;
                    }
                    else if (moves[0] == MOVE_R_DOUBLE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = HALF_WRIST + BAD_REGRIP;

                        x.grip = GRIP_THUMB_UP;
                        x.trick2 = TRICK_NONE;
                        distances_odd[coordinate_to_number(x)] = HALF_WRIST + BAD_REGRIP;
                    }
                    else if (moves[0] == MOVE_U_NORMAL){
                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_RIGHT_INDEX;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX;

                        x.grip = GRIP_THUMB_UP;
                        x.trick2 = TRICK_RIGHT_PINCH;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + BAD_REGRIP;
                    }
                    else if (moves[0] == MOVE_U_INVERSE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_LEFT_INDEX;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + GOOD_REGRIP;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_LEFT_INDEX;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX;

                        x.grip = GRIP_THUMB_UP;
                        x.trick2 = TRICK_LEFT_INDEX;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + GOOD_REGRIP;
                    }
                    else if (moves[0] == MOVE_U_DOUBLE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_LEFT_DOUBLE;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + GOOD_REGRIP;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_LEFT_DOUBLE;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_RIGHT_DOUBLE;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE;

                        x.grip = GRIP_THUMB_UP;
                        x.trick2 = TRICK_LEFT_DOUBLE;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + GOOD_REGRIP;
                    }
                    else if (moves[0] == MOVE_F_NORMAL){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_RIGHT_INDEX;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_INDEX + BAD_REGRIP;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_RIGHT_PINCH;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH;
                    }
                    else if (moves[0] == MOVE_F_INVERSE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_LEFT_PINCH;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + GOOD_REGRIP;

                        x.grip = GRIP_THUMB_FRONT;
                        x.trick2 = TRICK_LEFT_PINCH;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_PINCH + GOOD_REGRIP;
                    }
                    else if (moves[0] == MOVE_F_DOUBLE){
                        x.grip = GRIP_THUMB_DOWN;
                        x.trick2 = TRICK_RIGHT_DOUBLE;
                        distances_odd[coordinate_to_number(x)] = NONE_NONE_DOUBLE + BAD_REGRIP;
                    }   
                }
            }
            for (u64 i = 0; i < N; i++){
                if (distances_even[i] != INFINITY){
                    for (u64 j = 0; j < layer_move_size[moves[m]][i]; j++){
                        if (distances_even[i] + layer_move[moves[m]][i][j].cost < distances_odd[layer_move[moves[m]][i][j].to]){
                            distances_odd[layer_move[moves[m]][i][j].to] = distances_even[i] + layer_move[moves[m]][i][j].cost;
                        }
                    }
                }
            }
        }
        else{
            for (u64 i = 0; i < N; i++){
                distances_even[i] = INFINITY;
            }
            for (u64 i = 0; i < N; i++){
                if (distances_odd[i] != INFINITY){
                    for (u64 j = 0; j < layer_move_size[moves[m]][i]; j++){
                        if (distances_odd[i] + layer_move[moves[m]][i][j].cost < distances_even[layer_move[moves[m]][i][j].to]){
                            distances_even[layer_move[moves[m]][i][j].to] = distances_odd[i] + layer_move[moves[m]][i][j].cost;
                        }
                    }
                }
            }
        }
        
    }
        
    u64 result = INFINITY;
    for (u64 i = 0; i < N; i++){
        if (moves_size % 2 == 0){
            if (distances_even[i] < result){
                result = distances_even[i];
            }
        }
        else{
            if (distances_odd[i] < result){
                result = distances_odd[i];
            }
        }
        
    }
    
    for (u64 i = 0; i + 2 < moves_size; i++){
        if ((moves[i] / 3) != 0 && (moves[i + 1] / 3) != 0 && (moves[i + 2] / 3) != 0){
            result += 500;
        }
    }
    /*for (u64 i = 0; i + 1 < moves_size; i++){
        if ((moves[i] / 3) != 0 && (moves[i + 1] / 3) != 0){
            //result += 500;
            
            if (moves[i] == MOVE_U_NORMAL && moves[i + 1] == MOVE_F_INVERSE){
                result += 50;
            }
            else if (moves[i] == MOVE_U_INVERSE && moves[i + 1] == MOVE_F_NORMAL){
                result += 50;
            }
            else if (moves[i] == MOVE_F_NORMAL && moves[i + 1] == MOVE_U_INVERSE){
                result += 50;
            }
            else if (moves[i] == MOVE_F_INVERSE && moves[i + 1] == MOVE_U_NORMAL){
                result += 50;
            }

            else if (moves[i] == MOVE_U_INVERSE && moves[i] == MOVE_F_DOUBLE){
                result += 50;
            }
            else if (moves[i] == MOVE_U_DOUBLE && moves[i] == MOVE_F_DOUBLE){
                result += 50;
            }
            else if (moves[i] == MOVE_F_DOUBLE  && moves[i] == MOVE_U_INVERSE){
                result += 50;
            }
            else if (moves[i] == MOVE_F_DOUBLE  && moves[i] == MOVE_U_DOUBLE){
                result += 50;
            }
            else{
                result += 500;
            }
            
        }
    }*/
    
    return result;
}



#endif