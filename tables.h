#ifndef TABLES_H
#define TABLES_H

#include "types.h"
#include "constants.h"
#include "cube.h"

struct hash_table_cell{
    u64 key;
    u64 index;
};

struct cube cubes[STATES];
struct hash_table_cell hash_table[HASH_TABLE_SIZE];
u64 distances[STATES];
u64 graph[STATES][MOVES];

u64 unique_cubes[UNIQUE_STATES];
bool discovered[STATES];

u64 id(struct cube* c){
    u64 sum = 0;
    u64 base = 1;
    for (u64 x = 0; x < 2; x++){
        for (u64 y = 0; y < 2; y++){
            for (u64 z = 0; z < 2; z++){
                for (u64 d = 0; d < 3; d++){
                    sum += ((u64) c->stickers[x][y][z][d]) * base;
                    base *= 6;
                }
            }
        }
    }
    return sum;
}

u64 hash_table_hash(u64 key){ 
    key = (key ^ (key >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    key = (key ^ (key >> 27)) * UINT64_C(0x94d049bb133111eb);
    key = key ^ (key >> 31);
    return key % HASH_TABLE_SIZE; 
}

void hash_table_put(struct cube* c, u64 index){
    u64 key = id(c);
    u64 h = hash_table_hash(key);
    while (hash_table[h].key != 0 && hash_table[h].key != key){ //this only works because key is never 0
        h++;
        if (h >= HASH_TABLE_SIZE){
            h = 0;
        }
    }
    hash_table[h].key = key;
    hash_table[h].index = index;
}

struct hash_table_cell* hash_table_get(struct cube* c){
    u64 key = id(c);
    u64 h = hash_table_hash(key);
    while (hash_table[h].key != 0 && hash_table[h].key != key){ //this only works because key is never 0
        h++;
        if (h >= HASH_TABLE_SIZE){
            h = 0;
        }
    }
    if (hash_table[h].key == key){
        return &hash_table[h];
    }
    return NULL;
}

void tables_generator(){ 
    cube_constructor(&cubes[0]);
    hash_table_put(&cubes[0], 0);
    distances[0] = 0;
    u64 queue_next = 1;
    for (u64 s = 0; s < STATES; s++){
        if ((s + 1) % (3674160 / 10) == 0){
            u64 done = (s + 1) * 100 / 3674160;
            printf("%d%%\n", (int) (done));
        }
        struct cube c = cubes[s]; 
        for (u64 m = 0; m < MOVES; m++){
            switch (m % 3){
				case 0: cube_move(&c, m); break;
				case 1: cube_move(&c, m + 1); break;
				case 2: cube_move(&c, m - 1); break;
			}
            struct hash_table_cell* h = hash_table_get(&c);
            if (h == NULL){
                cubes[queue_next] = c;
                hash_table_put(&c, queue_next);
                distances[queue_next] = distances[s] + 1;
                graph[s][m] = queue_next;
                queue_next++;
            }
            else{
                graph[s][m] = h->index;
            }
            if (m % 3 == 2){
                cube_move(&c, m);
            }
        }
    }

    u64 unique_cubes_next = 0;
    for (u64 s = 0; s < STATES; s++){
        if (!discovered[s]){
            for (u64 r = 0; r < ANGLES; r++){
                struct cube c = cubes[s];
                cube_rotate(&c, r);
                cube_recolour(&c); 
                u64 i = hash_table_get(&c)->index;
                if (!discovered[i]){
                    discovered[i] = true;
                }
            }
            unique_cubes[unique_cubes_next] = s;
            unique_cubes_next++;
        }
    }
}

u64 cube_to_inverse(u64 c){
    struct cube normal = cubes[c];
    struct cube inverse;
    struct cube solved;
    cube_constructor(&solved);
    for (u64 x = 0; x < 2; x++){
        for (u64 y = 0; y < 2; y++){
            for (u64 z = 0; z < 2; z++){
                u64 xd;
                u64 yd;
                u64 zd;
                u64 d0;
                u64 d1;
                u64 d2;
                for (u64 d = 0; d < 3; d++){
                    switch (normal.stickers[x][y][z][d]){
                        case ORANGE: xd = 0; break;
                        case RED: xd = 1; break;
                        case YELLOW: yd = 0; break;
                        case WHITE: yd = 1; break;
                        case BLUE: zd = 0; break;
                        case GREEN: zd = 1; break;
                    }
                    switch (d){
                        case 0: d0 = normal.stickers[x][y][z][d] / 2; break;
                        case 1: d1 = normal.stickers[x][y][z][d] / 2; break;
                        case 2: d2 = normal.stickers[x][y][z][d] / 2; break;
                    } 
                }
                inverse.stickers[xd][yd][zd][d0] = solved.stickers[x][y][z][0];
                inverse.stickers[xd][yd][zd][d1] = solved.stickers[x][y][z][1];
                inverse.stickers[xd][yd][zd][d2] = solved.stickers[x][y][z][2];
            }
        }
    }    
    return hash_table_get(&inverse)->index;
}

#endif