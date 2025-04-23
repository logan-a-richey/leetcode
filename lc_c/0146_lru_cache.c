// lc 0146
// lru cache

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** map; // Hash map for O(1) access
} LRUCache;

/*****************************************************************************/
// declare

Node* createNode(int key, int val);
LRUCache* lRUCacheCreate(int capacity);
void removeNode(LRUCache* cache, Node* node);
void moveToHead(LRUCache* cache, Node* node);
int lRUCacheGet(LRUCache* cache, int key);
void lRUCachePut(LRUCache* cache, int key, int value) ;
void lRUCachePut(LRUCache* cache, int key, int value); 

/*****************************************************************************/
// define

Node* createNode(int key, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    cache->map = (Node**)malloc(capacity * sizeof(Node*));
    for (int i = 0; i < capacity; i++) {
        cache->map[i] = NULL;
    }
    return cache;
}

void removeNode(LRUCache* cache, Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
    cache->size--;
}

void moveToHead(LRUCache* cache, Node* node) {
    if (cache->head == node) return;
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == cache->tail) cache->tail = node->prev;

    node->prev = NULL;
    node->next = cache->head;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
    if (!cache->tail) cache->tail = node;
}

int lRUCacheGet(LRUCache* cache, int key) {
    if (cache->map[key % cache->capacity] != NULL &&
        cache->map[key % cache->capacity]->key == key
    ) {
        Node* node = cache->map[key % cache->capacity];
        moveToHead(cache, node);
        return node->val;
    }
    return -1;
}

void lRUCachePut(LRUCache* cache, int key, int value) {
    if (cache->map[key % cache->capacity] != NULL 
        && cache->map[key % cache->capacity]->key == key
    ) {
        Node* node = cache->map[key % cache->capacity];
        node->val = value;
        moveToHead(cache, node);
        return;
    }
    
    if (cache->size == cache->capacity) {  
        cache->map[cache->tail->key % cache->capacity] = NULL;
        removeNode(cache, cache->tail);
    }

    Node* newNode = createNode(key, value);
    newNode->next = cache->head;
    if (cache->head) {
      cache->head->prev = newNode;
    }
    cache->head = newNode;
    if (!cache->tail) {
        cache->tail = newNode;
    }
    cache->map[key % cache->capacity] = newNode;
    cache->size++;
}

void lRUCacheFree(LRUCache* cache) {
  Node* current = cache->head;
  while (current != NULL) {
    Node* next = current->next;
    free(current);
    current = next;
  }
  free(cache->map);
  free(cache);
}

/*****************************************************************************/
// test usage

// Leetcode requirement:
/*
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
*/

int main() {
    printf("Creating LRU Cache with capacity 2\n");
    LRUCache* cache = lRUCacheCreate(2);

    printf("Putting (1, 1)\n");
    lRUCachePut(cache, 1, 1); // cache: {1=1}

    printf("Putting (2, 2)\n");
    lRUCachePut(cache, 2, 2); // cache: {2=2, 1=1}

    printf("Getting key 1: %d\n", lRUCacheGet(cache, 1)); // returns 1, cache: {1=1, 2=2}

    printf("Putting (3, 3) -> should evict key 2\n");
    lRUCachePut(cache, 3, 3); // evicts key 2, cache: {3=3, 1=1}

    printf("Getting key 2 (should be -1): %d\n", lRUCacheGet(cache, 2)); // returns -1

    printf("Putting (4, 4) -> should evict key 1\n");
    lRUCachePut(cache, 4, 4); // evicts key 1, cache: {4=4, 3=3}

    printf("Getting key 1 (should be -1): %d\n", lRUCacheGet(cache, 1)); // returns -1
    printf("Getting key 3 (should be 3): %d\n", lRUCacheGet(cache, 3)); // returns 3
    printf("Getting key 4 (should be 4): %d\n", lRUCacheGet(cache, 4)); // returns 4

    printf("Freeing cache\n");
    lRUCacheFree(cache);
    return 0;
}

