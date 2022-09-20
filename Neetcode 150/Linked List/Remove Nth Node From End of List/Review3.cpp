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
    // 09/12/2022 Remove Nth Node from End of List (Medium)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use a dummy node to avoid edge cases having to deal with the head
        ListNode *dummy = new ListNode (0, head);
        ListNode *first = head, *second = dummy;
        
        // iterate first pointer n times 
        while (first != nullptr && n > 0) {
            n--;
            first = first -> next;
        }
        
        // start traversal of second poitner until first is null
        while (first != nullptr) {
            first = first -> next;
            second = second -> next;
        }
        
        // remove the nth node
        second -> next = second -> next -> next;
        
        // return head of list as dummy -> next to avoid edge cases with head
        return dummy -> next;
    }
};