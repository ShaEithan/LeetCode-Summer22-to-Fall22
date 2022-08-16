struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
// 08/15/2022 Reorder List O(N), O(1)
    void reorderList(ListNode* head) {
        
        if  (head -> next == nullptr) { // if there isn't anything to reorder
        // just return
            return;
        }
        
        // initializing our fast and slow pointers
        ListNode *fast = head, *slow = head, *previous = nullptr;
        

        // traverse until fast is the last node in the list
        while (fast != nullptr && fast -> next != nullptr) {
            previous = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        previous -> next = nullptr;
        
        // define our first and second halves

        ListNode *secondHalf = slow;
        ListNode *firstHalf = head;

        // reverse the second half
        secondHalf = reverse(secondHalf);
        

        // merge nodes
        while (firstHalf != nullptr) {
            // temp nodes to store next node in place
            ListNode *temp1 = firstHalf -> next;
            ListNode *temp2 = secondHalf -> next;
            
            // reordering in place
            firstHalf -> next = secondHalf;
            
            // if we reach the end of the first half, then
            // we can just stop.
            if (temp1 == nullptr) {
                break;
            }
            
            // attatch second half correctly
            secondHalf -> next = temp1;
            
            // move to the next nodes to merge
            firstHalf = temp1;
            secondHalf = temp2;
        }
        
        return;
        
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode *nextNode;
        ListNode *previous = nullptr;
        
        while (head != nullptr) {
            nextNode = head -> next;
            head -> next = previous;
            previous = head;
            head = nextNode;
        }
        
        return previous;
    }
};