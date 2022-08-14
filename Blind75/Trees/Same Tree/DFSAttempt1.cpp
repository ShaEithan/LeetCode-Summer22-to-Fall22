#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS Approach 06/03/2022

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // if either p or q is null, we check to see if the other is also null or not
        // and return based on that
        
        if (p == nullptr || q == nullptr)
        {
            return (p == q);
        }
        
        // Here is where we DFS traverse recursively, need to check if the current p and current q have th same value
        // and if so, we also check the children of both respectively and return based on that 
        return (p -> val == q -> val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        
        // Time Complexity: O(N), as worst case we need to traverse N nodes for both trees so O(N + N), asymptoticlly it's O(N)
        // Space Complexity: O(N), need space for the recursion stack, O(1) without concerning that
    }
};