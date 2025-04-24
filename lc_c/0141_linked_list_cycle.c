// lc 
// 0141 linked list cycle

#define MAX_NODES 100000

/*****************************************************************************/

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    int elements[MAX_NODES];
    int size;
} Set;

/*****************************************************************************/

void init_set(Set *set);
bool is_member(Set *set, int element);
bool add_element(Set *set, int element);

bool hasCycle(struct ListNode *head);

/*****************************************************************************/

void init_set(Set *set) {
    set->size = 0;
}

bool is_member(Set* set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return true;
        }
    }
    return false;
}

bool add_element(Set* set, int element) {
    if (set->size >= MAX_NODES || is_member(set, element)) {
        return false;
    }
    set->elements[set->size] = element;
    set->size++;
    return true;
}

/*****************************************************************************/

bool hasCycle(struct ListNode *head) {
    struct ListNode* nodes[MAX_NODES];
    struct ListNode* node = head;
    Set my_set;
    init_set(&my_set);

    while (node){
        // check to see if node was in the set
        node = node->next;
        if (!node){
            return false;
        }

        if (is_member(&my_set, (int)node)){
            return true;
        }

        add_element(&my_set, (int)node);
    }

    return false;   
}

