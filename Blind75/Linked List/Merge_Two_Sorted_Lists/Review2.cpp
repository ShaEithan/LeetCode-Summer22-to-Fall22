
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 09/05/2022
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *endOfList = dummy;
        
        while (list1 != nullptr & list2 != nullptr) {
            
            if (list1 -> val < list2 -> val) {
                endOfList -> next = list1;
                endOfList = endOfList -> next;
                list1 = list1 -> next;
            } else {
                endOfList -> next = list2;
                endOfList = endOfList -> next;
                list2 = list2 -> next;
            }
        }
        
        if (list1 == nullptr) {
            endOfList -> next = list2;
        } else {
            endOfList -> next = list1;
        }
        
        return dummy -> next;
    }
};