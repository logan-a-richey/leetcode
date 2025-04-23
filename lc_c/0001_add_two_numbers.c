// 0001_add_two_numbers.c
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// ============================================================================
// Declare header functions:
ListNode* create_node(int val);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* make_linked_list_number(int num);
void print_linked_list_number(ListNode* list);
void free_linked_list(ListNode* list);

// ============================================================================
// Define header functions
// Helper to create a new node
ListNode* create_node(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main function to add two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    ListNode* current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int x = 0;
        int y = 0;

        if (l1 != NULL) {
            x = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            y = l2->val;
            l2 = l2->next;
        }

        int sum = x + y + carry;
        carry = 0;

        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }

        current->next = create_node(sum);
        current = current->next;
    }

    return dummy.next;
}

// Convert an integer to a reversed linked list
ListNode* make_linked_list_number(int num) {
    if (num == 0) return create_node(0);

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while (num > 0) {
        int digit = num % 10;
        ListNode* node = create_node(digit);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        num /= 10;
    }

    return head;
}

// Print the linked list number
void print_linked_list_number(ListNode* list) {
    while (list != NULL) {
        printf("%d", list->val);
        list = list->next;
        if (list != NULL) printf(" -> ");
    }
    printf("\n");
}

// Free a linked list
void free_linked_list(ListNode* list) {
    while (list) {
        ListNode* temp = list;
        list = list->next;
        free(temp);
    }
}

/*****************************************************************************/
// test usage

int main() {
    ListNode* l1 = make_linked_list_number(123);
    ListNode* l2 = make_linked_list_number(456);
    ListNode* l3 = addTwoNumbers(l1, l2);

    printf("l1: ");
    print_linked_list_number(l1);
    printf("l2: ");
    print_linked_list_number(l2);
    printf("sum: ");
    print_linked_list_number(l3);

    // Clean up
    free_linked_list(l1);
    free_linked_list(l2);
    free_linked_list(l3);

    return 0;
}

