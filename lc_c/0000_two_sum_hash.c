// two_sum.c
// using hash tables for better perf

#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// map.h

#define MAP_TABLE_SIZE 10007

// define map structs:
typedef struct MapEntry {
    int key;              
    int value;
    struct MapEntry* next;
} MapEntry;

typedef struct HashMap {
    MapEntry* table[MAP_TABLE_SIZE];
} HashMap;

// hash function for int
unsigned int map_hash(int key) {
    return abs(key) % MAP_TABLE_SIZE;
}

// create new hash map
HashMap* map_create() {
    HashMap* map = malloc(sizeof(HashMap));
    for (int i = 0; i < MAP_TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

// insert key -> value pair
void map_insert(HashMap* map, int key, int value) {
    unsigned int idx = map_hash(key);
    MapEntry* entry = malloc(sizeof(MapEntry));
    entry->key = key;
    entry->value = value;
    entry->next = map->table[idx];
    map->table[idx] = entry;
}

// search for key -> returns value or -1 if not found
int map_search(HashMap* map, int key) {
    unsigned int idx = map_hash(key);
    MapEntry* current = map->table[idx];
    while (current) {
        if (current->key == key) return current->value;
        current = current->next;
    }
    return -1;
}

// free the map memory
void map_free(HashMap* map) {
    for (int i = 0; i < MAP_TABLE_SIZE; i++) {
        MapEntry* curr = map->table[i];
        while (curr) {
            MapEntry* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(map);
}

// ============================================================================
// two_sum

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashMap* map = map_create();

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = map_search(map, complement);
        if (foundIndex != -1) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            map_free(map);
            return result;
        }
        map_insert(map, nums[i], i);
    }

    *returnSize = 0;
    map_free(map);
    return NULL;
}

// ============================================================================
// test usage

int main() {
    int nums[] = {3, 2, 4};
    int target = 6;
    int returnSize;
    
    int* res = twoSum(nums, 3, target, &returnSize);
    
    if (res) {
        printf("[%d, %d]\n", res[0], res[1]);
        free(res);
    } else {
        printf("null\n");
    }
    
    return 0;
}

