#include <vector>
#include <queue>
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

class Solution {
public:
    // 09/13/2022
    // Time Complexity:
    // Space Complexity: 
    vector<vector<int>> levelOrder(TreeNode* root) {
        // need level by level traversal so use Tree BFS where we use a queue

        queue<TreeNode*> level;
        vector<vector<int>> result;
        
        if (root == nullptr) { // if there's nothing to traverse just return an empty array
            return result;
        }
        
        level.push(root);
        
        // once our queue is empty, then we know we've traversed everything
        while (!level.empty()) { 
            
            int currentLevelSize = level.size(); // current size of the queue is how many elements are on the current level
            vector<int> currentLevel;
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode *currentNode = level.front();
                level.pop();
                currentLevel.push_back(currentNode -> val);
                
                if (currentNode -> left != nullptr) {
                    level.push(currentNode -> left);
                }
                
                if (currentNode -> right != nullptr) {
                    level.push(currentNode -> right);
                }
            }
            
            result.push_back(currentLevel); // push traversed level into result array
        }
        
        return result;
    }
};