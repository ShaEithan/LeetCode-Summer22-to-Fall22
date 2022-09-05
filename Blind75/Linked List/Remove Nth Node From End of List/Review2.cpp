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
        ListNode *dummy = new ListNode (0,head);
        ListNode *first = head, *second = dummy;
        
        while (n > 0 && first != nullptr) {
            first = first -> next;
            n--;
        }
        
        while (first != nullptr) {
            second = second -> next;
            first = first -> next;
        }
        second -> next = second -> next -> next;
        
        return dummy -> next;
    }
};