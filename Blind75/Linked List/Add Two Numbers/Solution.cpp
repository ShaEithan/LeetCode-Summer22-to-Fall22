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
        
        // initialize a dummy node to void edge case of inserting into a LL
        ListNode *dummy = new ListNode(0);
        // current keeps track of the latest node sum added
        ListNode *current = dummy;
        
        // variable to keep track of carried values
        int carry = 0;
        
        // keeps adding until all of these are false
        // we keep traversing and adding until both lists are empty
        // and carry is 0
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            // if current node in l1 or l2 is not null, we assign the value of
            // the current node to a value we'll add later
            int value1 = l1 ? l1-> val : 0;
            int value2 = l2 ? l2-> val : 0;
            
            // calculate sum of the two values in the LL 
            // and the carry value if sum > 10
            int sum = value1 + value2 + carry;
            carry = sum / 10;
            
            // initalizee and add a new node to the result LL 
            // with the sum % 10, as we can only have one digit values
            current -> next = new ListNode(sum % 10);
            // traverse to newly created node 
            current = current -> next;
            
            // traverses to next node depending on if l1 or l2 is null or not
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        
        // return the head of the new list
        return dummy -> next;
        
        // Time Complexity: O(N), N being the length of the longer LL
        // Space Complexity: O(n), where N is the length of the largest LL + 1, as we have our
        // dummy node 
    }
};