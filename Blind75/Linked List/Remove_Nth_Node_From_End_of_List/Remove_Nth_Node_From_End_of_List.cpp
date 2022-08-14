struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 07/08/2022 remove Nth Node from End
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Create a Dummy Node, to deal with edge case of head being null
        // ListNode(0, head) initalizes it as node with value 0, and before the head of 
        // our LL 
        
        ListNode *dummy = new ListNode(0, head);
        
        // create 2 pointers, one that signals when we get to the end of the list
        // and another that tells us where the nth node is 
        ListNode *pointer1 = head;
        ListNode *pointernth = dummy;
      
        // the first pointer traverses n nodes ahead of the 2nd pointer,
        // so the second pointer lands on the node before the one we need to remove
        
        while (n > 0 && pointer1 != nullptr){
            pointer1 = pointer1 -> next;
            n--;
        }
        
        while (pointer1 != nullptr){
            pointernth = pointernth -> next;
            pointer1 = pointer1 -> next;
        }
        
        // remove the nth node by changing the address of the next node of n-1 to the
        // n + 1 node
        pointernth -> next = pointernth -> next -> next;
        
        return dummy -> next; // return the head of our LL 
        
        // Time Complexity: O(N) need to traverse N nodes
        // Space Complexity: O(1)
    }
};