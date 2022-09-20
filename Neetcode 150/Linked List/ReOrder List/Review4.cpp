struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 09/12/2022 Reorder List (Medium)
    void reorderList(ListNode* head) {
        
        // if there's only one node in the list, no need to reorder
        if (head -> next == nullptr) {
            return;
        }
        
        
        ListNode *fast = head, *slow = head, *previous = nullptr;
        // using fast and slow pointers to find midpoint of the list and separate first half
        // and second half 
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            previous = slow;
            slow = slow -> next;
        }
        
        previous -> next = nullptr;
        ListNode *secondHalf = reverse(slow);
        // reverse secondHalf so we can use two pointers to merge the list in the correct order later
        
        ListNode *firstHalf = head;
        
        // merge the two halves in the correct order, 
        // once firstHalf -> next is null (temp1) then there's
        // nothing else to merge
        while (firstHalf != nullptr) {
            ListNode *temp1 = firstHalf -> next;
            ListNode *temp2 = secondHalf -> next;
            
            firstHalf -> next = secondHalf;
            
            if (temp1 == nullptr) {
                break;
            }
            
            secondHalf -> next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
            
            
        return;
    }
private:
    ListNode *reverse(ListNode *head) {
        ListNode *previous = nullptr, *nextNode;
        
        while (head != nullptr) {
            nextNode = head -> next;
            head -> next = previous;
            previous = head;
            head = nextNode;
        }
        
        return previous;
    }
};