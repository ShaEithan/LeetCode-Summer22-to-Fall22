struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
    // 9/29/2022 Add 2 Numbers (Medium)
    // Time Complexity: O(N + M), need to iterate over N + M nodes and do operations on them
    // Space Complexity: O(N), N = the length of the output of LL
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); // dummy node to get rid of edge cases dealing with head nodes
        ListNode *endOfList = dummy; // keep track of the end of the list
        
        int carry = 0; // var to keep track of carry over values
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int value1 = l1 ? l1->val : 0; // conditional to decide what the value from l1 is
            // if null 0
            int value2 = l2 ? l2->val : 0; // same thing here
            // this says value 2 = l2 -> val if not null and 0 if null
            
            int sum = value1 + value2 + carry; // caluclate the current Sum
            carry = sum / 10; // divide sum by 10 to find how much is carried over to the next node
            
            endOfList -> next = new ListNode(sum % 10); // append new node to the end of the list
            endOfList = endOfList -> next; // traverse end of list
            
            // traverse l1 and l2 pointers depending on if that point in the list is null or not
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        
        // return head of the new LL
        return dummy -> next;
    }
};