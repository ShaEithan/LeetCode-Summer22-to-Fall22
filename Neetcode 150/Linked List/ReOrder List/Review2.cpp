struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // 08/29/2022 Reorder List (Medium) LL
    // Time Complexity: O(N), need to iterate and do operations on N nodes
    // Space Complexity: O(1) , no extra space needed
    
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head, *previous = nullptr;
        
        if (head -> next == nullptr) { // if there's only one node, there's nothing to reorder
            return;
        }
        
        // iterate a fast and slow pointer that tells us where the mid point of our list is
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            previous = slow; // previous will tell us where the end of the first half is 
            slow = slow -> next;
        }
        
        previous -> next = nullptr; // de link first and second half so we know where the 
        // end of the first list is
        
        ListNode *secondHalf = reverseList(slow); // reverse second half of the list
        // so it's easier for us to reorder later
        ListNode *firstHalf = head;

        while (firstHalf != nullptr) { // merging and reording our list
            // once firstHalf is null then we know we've finished merging properly
            ListNode *temp1 = firstHalf -> next;
            ListNode *temp2 = secondHalf -> next;
            
            firstHalf -> next = secondHalf;
            
            if (temp1 == nullptr) { // if we've reached the end of the first half, we can stop merging
                // because there's nothing left to merge
                break;
            }
            
            secondHalf -> next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
        
        return;
    }
private:
    ListNode* reverseList(ListNode *head) {
        ListNode *nextNode;
        ListNode *previous = nullptr;
        
        while (head != nullptr) {
            nextNode = head -> next;
            head -> next = previous;
            previous = head;
            head = nextNode;
        }
        // reversing LinkedList, O(N) O(1)
        return previous;
    }
};