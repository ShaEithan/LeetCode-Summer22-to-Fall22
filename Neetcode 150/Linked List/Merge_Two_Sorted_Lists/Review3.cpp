struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Time Complexity:  O(N), N is the total # of nodes as we need to traverse to every node
    // Space Complexity: O(1), no extra memory needed
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Because we need to insert nodes into each other in different order into a new list
        // we make a dummy node to get rid of edge cases that involve the head node
        ListNode *dummy = new ListNode();
        ListNode *endOfList = dummy; // keep track of the end of the list as that's where we insert
        
        // compare values of nodes of the list until one is null
        while (list1 != nullptr && list2 != nullptr) {
            
            if (list1 -> val < list2 -> val) {
                endOfList -> next = list1;
                list1 = list1 -> next;
            } else {
                endOfList -> next = list2;
                list2 = list2 -> next;
            }
            
            endOfList = endOfList -> next;
        }
        
        // depending on which one is null, append the rest of the remianing list to the end of our sorted list
        if (list1 == nullptr) {
            endOfList -> next = list2;
        } else {
            endOfList -> next = list1;
        }
        
        return dummy -> next;
    }
};