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
    // 08/28/2022 Remove Nth Node from End of List (Medium)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head); // use a dummy node
        // that is before the head, to get rid of edge cases that 
        // deal with the head
        ListNode *first = head, *second = dummy; // use two pointers
        
        
        while (n > 0 && first != nullptr) { // iterate first so that it's n nodes ahead
            first = first -> next;
            n--;
        }
            
        while (first != nullptr) { // once first is at the end of the list, second
            // will be at the nth node
            second = second -> next;
            first = first -> next;
        }
        
       second -> next = second -> next -> next; // adjust links so that we "remove" the nth node
        
        return dummy -> next;
    }
};