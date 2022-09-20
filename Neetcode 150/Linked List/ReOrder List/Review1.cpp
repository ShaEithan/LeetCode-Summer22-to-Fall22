struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        
        // if there's nothing to re order, then we just return
        if (head -> next == nullptr) {
            return;
        }
        
        ListNode *endOfFirst = nullptr; // pointer for us to mark the end of the first half
        ListNode *fast = head; // fast and slow pointers. Once fast pointer reaches the end of the list, slow will be at the half way point
        ListNode *slow = head;
        
        
        // find the half way point
        while (fast != nullptr && fast -> next != nullptr) {
            endOfFirst = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        endOfFirst -> next = nullptr; // de link the first half and second half to mark where we can stop merging and traversing
        
        ListNode *secondHalf = slow; // mark our second half 
        ListNode *nextNode; // used for reversal to reverse in place
        ListNode *previous = nullptr;
        
        while (secondHalf != nullptr) { // reverse our second half of the list
            nextNode = secondHalf -> next;
            secondHalf -> next = previous;
            previous = secondHalf;
            secondHalf = nextNode;
        }
        
        ListNode *second = previous; // after reversal, the head of the second half is now previous
        ListNode *first = head; 
        
        // we now iterate until our first pointer is now null signalling we've reached and reordereed all our valuese
        while (first != nullptr) {
            ListNode *temp1 = first -> next; // temp variables to hold address for our next values to merge
            ListNode *temp2 = second -> next; 
            
            first -> next = second; // begin reordering 
            
            if (temp1 == nullptr) { // if we've reached the end of the first half, there's nothing else to merge/reorder
                break;
            }
        
            second -> next = temp1; // attatch second half to the next node of the first half
            
            first = temp1; // move our first and second half pointers to the nex
            second = temp2;
        }
        
    }
};