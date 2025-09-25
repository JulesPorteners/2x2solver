#ifndef EVALUATION_H
#define EVALUATION_H

#include "types.h"
#include "constants.h"

struct coordinate{
    u64 grip;
    u64 trick1;
    u64 trick2;
    coordinate(){

    }
    coordinate(u64 grip, u64 trick1, u64 trick2){
        this->grip = grip;
        this->trick1 = trick1;
        this->trick2 = trick2;
    }
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

struct edge{
    u64 to;
    u64 cost;
};

struct edge layer_move[9][COORDINATES][7]; //todo make constant
u64 layer_move_size[9][COORDINATES];

void add_edge(u64 move, u64 i, u64 grip, u64 trick1, u64 trick2, u64 cost){

    struct coordinate v;
    v.grip = grip;
    v.trick1 = trick1;
    v.trick2 = trick2;
    u64 j = coordinate_to_number(v);

    layer_move[move][i][layer_move_size[move][i]].to = j;
    layer_move[move][i][layer_move_size[move][i]].cost = cost;
    layer_move_size[move][i]++;
    if (layer_move_size[move][i] > 7){
        printf("ERROR: layer_move_size[move][i] > 7\n");
    }
}

u64 get_cost(u64 history1, u64 history2, u64 next){
    u64 result;

    if (history2 == TRICK_NONE){
        if (history1 == TRICK_NONE && next == TRICK_RIGHT_PINCH){ result = NONE_NONE_PINCH; }
        else if (history1 == TRICK_NONE && next == TRICK_RIGHT_INDEX){ result = NONE_NONE_INDEX; }
        else if (history1 == TRICK_NONE && next == TRICK_RIGHT_MIDDLE){ result = NONE_NONE_MIDDLE; }
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
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_MIDDLE){ result = MIDDLE_NONE_MIDDLE; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_DOUBLE){ result = MIDDLE_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_MIDDLE && next == TRICK_RIGHT_PUSH){ result = MIDDLE_NONE_PUSH; }

        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_PINCH){ result = DOUBLE_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_INDEX){ result = DOUBLE_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_MIDDLE){ result = DOUBLE_NONE_MIDDLE; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_DOUBLE){ result = DOUBLE_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_DOUBLE && next == TRICK_RIGHT_PUSH){ result = DOUBLE_NONE_PUSH; }

        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_PINCH){ result = PUSH_NONE_PINCH; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_INDEX){ result = PUSH_NONE_INDEX; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_MIDDLE){ result = PUSH_NONE_MIDDLE; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_DOUBLE){ result = PUSH_NONE_DOUBLE; }
        else if (history1 == TRICK_RIGHT_PUSH && next == TRICK_RIGHT_PUSH){ result = PUSH_NONE_PUSH; }


        else if (history1 == TRICK_NONE && next == TRICK_LEFT_PINCH){ result = NONE_NONE_PINCH; }
        else if (history1 == TRICK_NONE && next == TRICK_LEFT_INDEX){ result = NONE_NONE_INDEX; }
        else if (history1 == TRICK_NONE && next == TRICK_LEFT_MIDDLE){ result = NONE_NONE_MIDDLE; }
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
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_MIDDLE){ result = MIDDLE_NONE_MIDDLE; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_DOUBLE){ result = MIDDLE_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_MIDDLE && next == TRICK_LEFT_PUSH){ result = MIDDLE_NONE_PUSH; }

        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_PINCH){ result = DOUBLE_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_INDEX){ result = DOUBLE_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_MIDDLE){ result = DOUBLE_NONE_MIDDLE; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_DOUBLE){ result = DOUBLE_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_DOUBLE && next == TRICK_LEFT_PUSH){ result = DOUBLE_NONE_PUSH; }

        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_PINCH){ result = PUSH_NONE_PINCH; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_INDEX){ result = PUSH_NONE_INDEX; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_MIDDLE){ result = PUSH_NONE_MIDDLE; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_DOUBLE){ result = PUSH_NONE_DOUBLE; }
        else if (history1 == TRICK_LEFT_PUSH && next == TRICK_LEFT_PUSH){ result = PUSH_NONE_PUSH; }
        
        /* alternating hands */
        else if (next == TRICK_LEFT_PINCH){ result = NONE_NONE_PINCH; }
        else if (next == TRICK_LEFT_INDEX){ result = NONE_NONE_INDEX; }
        else if (next == TRICK_LEFT_MIDDLE){ result = NONE_NONE_MIDDLE; }
        else if (next == TRICK_LEFT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (next == TRICK_LEFT_PUSH){ result = NONE_NONE_PUSH; }  

        else if (next == TRICK_RIGHT_PINCH){ result = NONE_NONE_PINCH; }
        else if (next == TRICK_RIGHT_INDEX){ result = NONE_NONE_INDEX; }
        else if (next == TRICK_RIGHT_MIDDLE){ result = NONE_NONE_MIDDLE; }
        else if (next == TRICK_RIGHT_DOUBLE){ result = NONE_NONE_DOUBLE; }
        else if (next == TRICK_RIGHT_PUSH){ result = NONE_NONE_PUSH; } 

        else{
            result = INFINITY;
        }
    }

    else if (history1 == TRICK_NONE && history2 != TRICK_NONE){
        bool h2l = history2 == TRICK_LEFT_PINCH || history2 == TRICK_LEFT_INDEX || history2 == TRICK_LEFT_MIDDLE || history2 == TRICK_LEFT_DOUBLE ;//|| history2 == TRICK_LEFT_PUSH;
        bool h2r = history2 == TRICK_RIGHT_PINCH || history2 == TRICK_RIGHT_INDEX || history2 == TRICK_RIGHT_MIDDLE || history2 == TRICK_RIGHT_DOUBLE ;//|| history2 == TRICK_RIGHT_PUSH;
        bool nl = next == TRICK_LEFT_PINCH || next == TRICK_LEFT_INDEX || next == TRICK_LEFT_MIDDLE || next == TRICK_LEFT_DOUBLE  ;//|| next == TRICK_LEFT_PUSH;
        bool nr = next == TRICK_RIGHT_PINCH || next == TRICK_RIGHT_INDEX || next == TRICK_RIGHT_MIDDLE || next == TRICK_RIGHT_DOUBLE  ;//|| next == TRICK_RIGHT_PUSH;
        if (history2 == TRICK_RIGHT_PINCH && next == TRICK_RIGHT_MIDDLE){
            result = PINCH_MIDDLE;
        }
        else if (history2 == TRICK_LEFT_PINCH && next == TRICK_LEFT_MIDDLE){
            result = PINCH_MIDDLE;
        }
        else if (next == TRICK_RIGHT_MIDDLE || next == TRICK_LEFT_MIDDLE){
            result = INFINITY;
        }
        else if ((h2l && nr) || (h2r && nl)){

            if (next == TRICK_LEFT_PINCH){ result = NONE_NONE_PINCH + 25; }
            else if (next == TRICK_LEFT_INDEX){ result = NONE_NONE_INDEX + 25; }
            else if (next == TRICK_LEFT_DOUBLE){ result = NONE_NONE_DOUBLE + 25; }
            //else if (next == TRICK_LEFT_PUSH){ result = INFINITY; } // todo check how to approach this //NONE_NONE_PUSH + 25; }  

            else if (next == TRICK_RIGHT_PINCH){ result = NONE_NONE_PINCH + 25; }
            else if (next == TRICK_RIGHT_INDEX){ result = NONE_NONE_INDEX + 25; }
            else if (next == TRICK_RIGHT_DOUBLE){ result = NONE_NONE_DOUBLE + 25; }
            //else if (next == TRICK_RIGHT_PUSH){ result = INFINITY; }  // todo check how to approach this // NONE_NONE_PUSH + 25; 

            else{
                result = INFINITY;
            }
        }
        else{ 
            result = UNDEFINED_UF; //UNDEFINED_UF;
        } 
    }
    else{
        bool h1l = 
            history1 == TRICK_LEFT_PINCH 
            || history1 == TRICK_LEFT_INDEX 
            || history1 == TRICK_LEFT_MIDDLE 
            || history1 == TRICK_LEFT_DOUBLE ;
        bool h1r = 
            history1 == TRICK_RIGHT_PINCH 
            || history1 == TRICK_RIGHT_INDEX 
            || history1 == TRICK_RIGHT_MIDDLE 
            || history1 == TRICK_RIGHT_DOUBLE ;
        bool h2l = 
            history2 == TRICK_LEFT_PINCH 
            || history2 == TRICK_LEFT_INDEX 
            || history2 == TRICK_LEFT_MIDDLE 
            || history2 == TRICK_LEFT_DOUBLE ;
        bool h2r = 
            history2 == TRICK_RIGHT_PINCH 
            || history2 == TRICK_RIGHT_INDEX 
            || history2 == TRICK_RIGHT_MIDDLE 
            || history2 == TRICK_RIGHT_DOUBLE ;
        bool nl = 
            next == TRICK_LEFT_PINCH 
            || next == TRICK_LEFT_INDEX 
            || next == TRICK_LEFT_MIDDLE 
            || next == TRICK_LEFT_DOUBLE ;
        bool nr = 
            next == TRICK_RIGHT_PINCH 
            || next == TRICK_RIGHT_INDEX 
            || next == TRICK_RIGHT_MIDDLE 
            || next == TRICK_RIGHT_DOUBLE ;
        if ((h1r && h2l && nr) || (h1l && h2r && nl)){
            result = INFINITY;
            //result = 25 + get_cost(history1, TRICK_NONE, next);
        }
        else{
            result = INFINITY;
        }
        
    }

    return result;
}

void init_layers(){
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
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_INDEX, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    if (u.trick1 == TRICK_LEFT_INDEX || u.trick2 == TRICK_LEFT_PINCH){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                        add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_MIDDLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_FRONT){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_INDEX, get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_LEFT_INDEX, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    add_edge(m, i, GRIP_THUMB_UP, u.trick2, TRICK_LEFT_INDEX, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PUSH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PUSH));
                    if (u.trick1 == TRICK_LEFT_INDEX || u.trick2 == TRICK_LEFT_PINCH){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                        add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_LEFT_MIDDLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                        add_edge(m, i, GRIP_THUMB_UP, u.trick2, TRICK_LEFT_MIDDLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_INDEX, get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_INDEX, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_INDEX));
                    if (u.trick1 == TRICK_LEFT_INDEX){
                        add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_MIDDLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                        add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_MIDDLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_MIDDLE));
                    }
                }
            }
            else if (m == MOVE_U_DOUBLE){
                if (u.grip == GRIP_THUMB_DOWN){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_DOUBLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                }
                else if (u.grip == GRIP_THUMB_FRONT){ 
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_LEFT_DOUBLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, GRIP_THUMB_UP, u.trick2, TRICK_LEFT_DOUBLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_RIGHT_DOUBLE));
                }
                else if (u.grip == GRIP_THUMB_UP){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_DOUBLE, get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
                    add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_DOUBLE, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_DOUBLE));
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
                    //add_edge(m, i, GRIP_THUMB_FRONT, u.trick2, TRICK_LEFT_PINCH, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_PINCH));
                    add_edge(m, i, u.grip, u.trick2, TRICK_RIGHT_PUSH, get_cost(u.trick1, u.trick2, TRICK_RIGHT_PUSH));
                }
                else if (u.grip == GRIP_THUMB_FRONT){  
                    add_edge(m, i, u.grip, u.trick2, TRICK_LEFT_PINCH, get_cost(u.trick1, u.trick2, TRICK_LEFT_PINCH));
                    //add_edge(m, i, GRIP_THUMB_DOWN, u.trick2, TRICK_LEFT_PINCH, QUARTER_REGRIP + get_cost(u.trick1, u.trick2, TRICK_LEFT_PINCH));
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

struct distance{
    u64 distances[COORDINATES];
    bool visited[COORDINATES];
    u64 visited_list[COORDINATES];
    u64 visited_list_size; 
    distance(){
        for (u64 i = 0; i < COORDINATES; i++){
            distances[i] = INFINITY;
            visited[i] = false;
            visited_list_size = 0;
        }
    }
    void update(u64 coord, u64 cost){
        distances[coord] = cost;
        visited[coord] = true;
        visited_list[visited_list_size] = coord;
        visited_list_size++;
    }
    void reset(){
        for (u64 i = 0; i < visited_list_size; i++){
            u64 ii = visited_list[i];
            distances[ii] = INFINITY;
            visited[ii] = false;
        }
        visited_list_size = 0;
    }
    void first_move(u64 m){ 
        switch (m){
            case MOVE_R_NORMAL: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_NONE)), QUARTER_WRIST + BAD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_UP, TRICK_NONE, TRICK_NONE)), QUARTER_WRIST + PICKUP);
                break;
            case MOVE_R_INVERSE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_NONE)), QUARTER_WRIST + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_NONE)), QUARTER_WRIST + BAD_REGRIP + PICKUP);
                break;
            case MOVE_R_DOUBLE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_NONE)), HALF_WRIST + BAD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_UP, TRICK_NONE, TRICK_NONE)), HALF_WRIST + BAD_REGRIP + PICKUP);
                break;
            case MOVE_U_NORMAL: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_RIGHT_INDEX)), NONE_NONE_INDEX + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_UP, TRICK_NONE, TRICK_RIGHT_PINCH)), NONE_NONE_PINCH + BAD_REGRIP + PICKUP);
                break;
            case MOVE_U_INVERSE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_LEFT_INDEX)), NONE_NONE_INDEX + GOOD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_LEFT_INDEX)), NONE_NONE_INDEX + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_UP, TRICK_NONE, TRICK_LEFT_INDEX)), NONE_NONE_INDEX + GOOD_REGRIP + PICKUP);
                break;
            case MOVE_U_DOUBLE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_LEFT_DOUBLE)), NONE_NONE_DOUBLE + GOOD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_LEFT_DOUBLE)), NONE_NONE_DOUBLE + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_RIGHT_DOUBLE)), NONE_NONE_DOUBLE + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_UP, TRICK_NONE, TRICK_LEFT_DOUBLE)), NONE_NONE_DOUBLE + GOOD_REGRIP + PICKUP);
                break;
            case MOVE_F_NORMAL: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_RIGHT_INDEX)), 25 + NONE_NONE_INDEX + BAD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_RIGHT_PINCH)), 25 + NONE_NONE_PINCH + PICKUP);
                break;
            case MOVE_F_INVERSE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_LEFT_PINCH)), 25 + NONE_NONE_PINCH + GOOD_REGRIP + PICKUP);
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_LEFT_PINCH)), 25 + NONE_NONE_PINCH + GOOD_REGRIP + PICKUP);
                break;
            case MOVE_F_DOUBLE: 
                this->update(coordinate_to_number(coordinate(GRIP_THUMB_DOWN, TRICK_NONE, TRICK_RIGHT_DOUBLE)), 25 + NONE_NONE_DOUBLE + BAD_REGRIP + PICKUP);
                break;
        } 
    }
};

u64 eval(u64 moves[MAX_MOVES], u64 moves_size){
    struct distance even;
    struct distance odd;
    even.update(coordinate_to_number(coordinate(GRIP_THUMB_FRONT, TRICK_NONE, TRICK_NONE)), 0);
    for (u64 m = 0; m < moves_size; m++){
        if (m % 2 == 0){
            odd.reset();
            if (m == 0){
                odd.first_move(moves[0]);         
            }
            else{
                for (u64 i = 0; i < even.visited_list_size; i++){
                    u64 ii = even.visited_list[i];
                    for (u64 j = 0; j < layer_move_size[moves[m]][ii]; j++){
                        if (even.distances[ii] + layer_move[moves[m]][ii][j].cost < odd.distances[layer_move[moves[m]][ii][j].to]){
                            odd.update(layer_move[moves[m]][ii][j].to, even.distances[ii] + layer_move[moves[m]][ii][j].cost);
                        }
                    }
                }
            }
        }
        else{
            even.reset();
            for (u64 i = 0; i < odd.visited_list_size; i++){
                u64 ii = odd.visited_list[i];
                for (u64 j = 0; j < layer_move_size[moves[m]][ii]; j++){
                    if (odd.distances[ii] + layer_move[moves[m]][ii][j].cost < even.distances[layer_move[moves[m]][ii][j].to]){
                        even.update(layer_move[moves[m]][ii][j].to, odd.distances[ii] + layer_move[moves[m]][ii][j].cost);
                    }
                }
            }
        } 
    }
        
    u64 result = INFINITY;
    if (moves_size % 2 == 0){
        for (u64 i = 0; i < even.visited_list_size; i++){
            u64 ii = even.visited_list[i];
            if (even.distances[ii] < result){
                result = even.distances[ii];
            }
        }
    }
    else{
        for (u64 i = 0; i < odd.visited_list_size; i++){
            u64 ii = odd.visited_list[i];
            if (odd.distances[ii] < result){
                result = odd.distances[ii];
            }
        }
    }

    return result;
}

#endif