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
}

#endif