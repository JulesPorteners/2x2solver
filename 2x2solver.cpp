#include <iostream>
#include <string>
#include <sstream>

#include "types.h"
#include "constants.h"
#include "cube.h"
#include "tables.h"
#include "evaluation.h"
#include "solver.h"

using namespace std;

bool get_moves(u64* cc, string* line){
    stringstream s(*line); 
    string move;
    u64 c = 0;
    bool valid = true;
    while (s >> move){
        if (move == "R"){
            c = graph[c][MOVE_R_NORMAL];
        }
        else if (move == "R'"){
            c = graph[c][MOVE_R_INVERSE];
        }
        else if (move == "R2"){
            c = graph[c][MOVE_R_DOUBLE];
        }
        else if (move == "R2'"){
            c = graph[c][MOVE_R_DOUBLE];
        }
        else if (move == "U"){
            c = graph[c][MOVE_U_NORMAL];
        }
        else if (move == "U'"){
            c = graph[c][MOVE_U_INVERSE];
        }
        else if (move == "U2"){
            c = graph[c][MOVE_U_DOUBLE];
        }
        else if (move == "U2'"){
            c = graph[c][MOVE_U_DOUBLE];
        }
        else if (move == "F"){
            c = graph[c][MOVE_F_NORMAL];
        }
        else if (move == "F'"){
            c = graph[c][MOVE_F_INVERSE];
        }
        else if (move == "F2"){
            c = graph[c][MOVE_F_DOUBLE];
        }
        else if (move == "F2'"){
            c = graph[c][MOVE_F_DOUBLE];
        }
        else{
            valid = false;
        }
    }
    *cc = c;
    return valid;
}

void output_solution(){ 
    if (solution_value == INFINITY){
        cout << "ERROR: no good solution found\n";
        return;
    }
    string output = "";
    for (u64 i = 0; i < rotations_size; i++){
        switch (rotations[i]){
            case ROTATION_X_NORMAL: output += ("x "); break;
            case ROTATION_X_INVERSE: output += ("x' "); break;
            case ROTATION_X_DOUBLE: output += ("x2 "); break;
            case ROTATION_Y_NORMAL: output += ("y "); break;
            case ROTATION_Y_INVERSE: output += ("y' "); break;
            case ROTATION_Y_DOUBLE: output += ("y2 "); break;
            case ROTATION_Z_NORMAL: output += ("z "); break;
            case ROTATION_Z_INVERSE: output += ("z' "); break;
            case ROTATION_Z_DOUBLE: output += ("z2 "); break;
        }
    }
    for (u64 i = 0; i < solution_size; i++){
        switch (solution[i]){
            case MOVE_R_NORMAL: output += ("R "); break;
            case MOVE_R_INVERSE: output += ("R' "); break;
            case MOVE_R_DOUBLE: output += ("R2 "); break;
            case MOVE_U_NORMAL: output += ("U "); break;
            case MOVE_U_INVERSE: output += ("U' "); break;
            case MOVE_U_DOUBLE: output += ("U2 "); break;
            case MOVE_F_NORMAL: output += ("F "); break;
            case MOVE_F_INVERSE: output += ("F' "); break;
            case MOVE_F_DOUBLE: output += ("F2 "); break;
        }
    }
    output += ("\n");
    cout << output;

}

u64 get_example(){
    u64 example = 0;
    example = graph[example][MOVE_R_INVERSE];
    example = graph[example][MOVE_U_DOUBLE];
    example = graph[example][MOVE_F_NORMAL];
    example = graph[example][MOVE_U_INVERSE];
    example = graph[example][MOVE_F_NORMAL];
    example = graph[example][MOVE_R_INVERSE];
    example = graph[example][MOVE_F_NORMAL];
    example = graph[example][MOVE_U_INVERSE];
    example = graph[example][MOVE_R_DOUBLE];
    example = graph[example][MOVE_U_INVERSE];
    example = graph[example][MOVE_R_INVERSE];
    return example;
}

int main(){
    cout << "Loading..\n";
    tables_generator();
    init_layers();

    /*
    for (u64 i = 0; i < UNIQUE_STATES; i++){
        solve(unique_cubes[i]);
        output_solution();
        solution_value = INFINITY;
        solution_size = 0;
        rotations_size = 0;
    }*/

    cout << "\nEnter a 2x2 scramble using the following moves:\nR R' R2 U U' U2 F F' F2\n\n";

    cout << "Example:\n";
    cout << "> R' U2 F U' F R' F U' R2 U' R'\n";
    u64 example = get_example();
    
    solve(example);
    //cout << solution_value << ": ";
    output_solution();
    solution_value = INFINITY;
    solution_size = 0;
    rotations_size = 0;

    cout << "\n> ";
    string line;
    while (getline(cin, line)){ 
        u64 c;
        bool valid = get_moves(&c, &line);
        if (valid){
            solve(c);

            /*u64 cc = c;
            for (u64 pre = 0; pre < 4; pre++){
                cc = cube_to_inverse(cc);
                switch (pre){
                    case 0: cc = cc; break;
                    case 1: cc = graph[cc][MOVE_U_NORMAL]; break; 
                    case 2: cc = graph[cc][MOVE_U_INVERSE]; break;
                    case 3: cc = graph[cc][MOVE_U_DOUBLE]; break;
                }
                cc = cube_to_inverse(cc);
                for (u64 post = 0; post < 4; post++){
                    switch (post){
                        case 0: cc = cc; break;
                        case 1: cc = graph[cc][MOVE_U_NORMAL]; break; 
                        case 2: cc = graph[cc][MOVE_U_INVERSE]; break;
                        case 3: cc = graph[cc][MOVE_U_DOUBLE]; break;
                    }
                    solve(cc);
                }
            }*/

            //cout << solution_value << ": ";
            output_solution();
            solution_value = INFINITY;
            solution_size = 0;
            rotations_size = 0;

        }
        else{
            cout << "invalid move\n";
        }
        cout << "\n> ";
    }
    return 0;
}

