struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

};
// 10/01/2022 Add 2 Numbers (Medium)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *endOfList = dummy;
        
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int value1 = l1 ? l1 -> val : 0;
            int value2 = l2 ? l2 -> val : 0;
            
            int sum = value1 + value2 + carry;
            carry = sum / 10;
            
            endOfList -> next = new ListNode(sum % 10);
            endOfList = endOfList -> next;
            
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        
        return dummy -> next;
    }
};