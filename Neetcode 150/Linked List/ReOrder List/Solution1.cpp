#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Time Complexity: O(N), traverse/merge N nodes, and reverse N/2 nodes O(N + N/2) = O(N)
    // Space Complexity: O(1), no extra space needed, modified in place
    void reorderList(ListNode* head) {
        
        // if there is only one node, we don't need to reorder it
        if (head->next == NULL) {
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // find the middle node of the list, so we can split the list into halves
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // de links the last node in the first half and the first node of the second half
        // gives us a stopping point between the first half and second half
        prev->next = NULL;
        
        
        ListNode* l1 = head; // head of the first half
        ListNode* l2 = reverse(slow); // after reversal, this returns the head of the second half
        
        merge(l1, l2); //. merge 2 linked list halves
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        // reverse linked list
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev; // return previous because it's the new head of the reversed list
    }
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) { // modify in place using temp variables
            ListNode* p1 = l1->next; // temp variable eto hold first halves next node
            ListNode* p2 = l2->next;// second halves next node
            
            l1->next = l2; // make first pointer's next node point to the second half's node
            
            if (p1 == NULL) { // if we reach the end of the first half, we stop re ordering
                break;
            }
            
            l2->next = p1; // the node that goes after the second half's node is the next node
            // in the first half the list. 
            
            // traverse to the next node of each list to add
            l1 = p1;
            l2 = p2;
        }
    }
};