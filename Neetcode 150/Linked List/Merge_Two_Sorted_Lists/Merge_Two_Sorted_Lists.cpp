
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// 07/08/2022 Merge Two Sorted Lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //Splicing together nodes of two lists meanss that we can't make any new ones
        // we must use the nodes we're given
        
        // Start by initializing current nodes for the head of each list
    
        ListNode *current1 = list1;
        ListNode *current2 = list2;
        
        // Initialize a dummy node to avoid edge case in the event that both lists are empty
        // our real output that we return is the node after the dummy_output
        // need to initialize space for a dummy node otherwise we'd have a null error issue
        ListNode *dummy_output = new ListNode();
        
        // Node to keep track of the end of our current output, nothing in our list yet
        // so it's our dummy node
        ListNode *current_end_of_output = dummy_output;
        
        if (list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        
        // compare both LL as long as both of our pointers are not past the end of each list
        while (current1 != nullptr && current2 != nullptr){
            
            // depending on if current1 or current2 is smaller, we 
            // append the next node to our tail of the output list
            
            if (current1 -> val < current2 -> val){
                current_end_of_output -> next = current1;
                current1 = current1 -> next;
            }
            else{
                current_end_of_output -> next = current2;
                current2 = current2 -> next;
            }
            // update our tail pointer to the node we just added to the output
            current_end_of_output = current_end_of_output -> next; 
        }
        
        // if we reach the end of one of the lists, but the other still has nodes,
        // we just append the rest of the nodes to the tail
        
        if (current1 == nullptr){
            current_end_of_output -> next = current2;
        }
        else if (current2 == nullptr){
            current_end_of_output -> next = current1;
        }
        
        return dummy_output -> next; // return the node after our dummy node because
        // that's where our output list starts
        
        // Time Complexity: O(N), N for the number of nodes in List 1  and 2, need to
        // compare them all worst case
        // Space Complexity: O(1)
    }
};