#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head); // dummy node
        // helps us with some edge cases, but also helps us find node n - 1
        // that we need to remove the Nth node
        
        ListNode *first = head; // first pointer, needs to iterate to the end of the list
        ListNode *second = dummy; // once first pointer gets to the end of the list
        // second -> next will be the node we need to remove or otherwise known as n - 1
        
        while (n > 0 && first != nullptr) { // iterate first node n times
            first = first -> next;
            n--;
        }
        
        // because we've already iterated n times, once first pointer
        // gets to the end of the list, second will have iterated to the node
        // before the node we need to remove

        while (first != nullptr) {
            second = second -> next;
            first = first -> next;
        }
        
        // change the link of the next node after second 
        // to the node after the next node to "remove" it
        second -> next = second -> next -> next;
        
        return dummy -> next; // return head of the LL
    }

    // Time Complexity: O(N), need to iterate over one pass of the list of N nodes
    // Space Complexity: O(1)
};