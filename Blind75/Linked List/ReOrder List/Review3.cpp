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
        
        if (head -> next == nullptr) {
            return; 
        }
        ListNode *fast = head, *slow = head, *previous = nullptr;
        
        while (fast != nullptr && fast -> next != nullptr) {
            previous = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode *secondHalf = slow;
        previous -> next = nullptr;
        
        secondHalf = reverseList(slow);
        
        ListNode *firstHalf = head;
        
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
    ListNode *reverseList(ListNode *head) {
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