
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 08/29/2022 Merge Two Sorted Lists (Easy) 
    
    // Time Complexity: O(N + M), need to iterate over N + M nodes worst case and append them
    // Space Complexity: O(1), no extra space needed we just append nodes together
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *dummy = new ListNode(); // dummy node where we'll insert into
        // the next node should be the head of our new merged LL
        ListNode *endOfOutput = dummy; // node tracking where the end of our merged linked list is
        
        if (list1 == nullptr && list2 == nullptr) { // if both lists are null at the head, then there's nothing to return, so we return null
            return nullptr;
        }
        
        while (list1 != nullptr && list2 != nullptr) { // we compare values of each node until one becomes null (meaning we reached the end of that list)
            
            if (list1 -> val < list2 -> val) {
                endOfOutput -> next = list1;
                list1 = list1 -> next;
            } else {
                endOfOutput -> next = list2;
                list2 = list2 -> next;
            }
            
            endOfOutput = endOfOutput -> next; // traverse to the new end node we added to the merged linked list
        }
        
        // depending on which list we got to the end of, we append 
        // the remaining nodes to the end of our merged linked list
        if (list1 == nullptr) {
            endOfOutput -> next = list2;
        } else {
            endOfOutput -> next = list1;
        }
        
        return dummy -> next; // the node after our dummy node is the head of our merged linked list
    }
};