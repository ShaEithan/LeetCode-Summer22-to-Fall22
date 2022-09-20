#include <iostream>
#include <unordered_set>

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
    bool hasCycle(ListNode *head) {
        
        ListNode *current = head;
        unordered_set<ListNode*> visited;
        
        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return true;
            }
            
            visited.insert(current);
            
            current = current -> next;
        }
        
        
        return false;
    }
};