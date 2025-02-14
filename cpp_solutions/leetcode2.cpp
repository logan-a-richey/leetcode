// 02_add_two_numbers.cpp

#include <iostream>

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tempHead = new ListNode(); 
        ListNode *current = tempHead;  
        int carry = 0;  

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return tempHead->next;
    }
};

// Helper function to print the list (for testing)
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example: 342 + 465 = 807
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3)));  
    ListNode* l2 = new ListNode(4, new ListNode(5, new ListNode(6)));  

    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    std::cout << "Number 1: " << std::endl;
    printList(l1);  
    std::cout << "Number 2: " << std::endl;
    printList(l2);  
    std::cout << "Result: " << std::endl;
    printList(result);  
    return 0;
}
