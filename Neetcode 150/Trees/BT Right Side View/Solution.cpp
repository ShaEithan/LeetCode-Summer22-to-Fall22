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
    // 10/10/2022  BT Right Side View (Medium) BFS
    // Time Complexity: O(N), need to push N nodes into queue
    // Space Complexity: O(N), worst case our BT is a LL and has N nodes 
    
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        queue<TreeNode*> nodeQ;
        vector<int> result;
        
        // do BFS traversal
        // the right most node on the level is the one we want to push into our result
        nodeQ.push(root);
        
        while (!nodeQ.empty()) {
            int levelSize = nodeQ.size(); // current size of the level being traversed, this also tells us what node is on our "right" view
            
            // traverse the level of size level size, the first element in the queue
            // is our right view because we're pushing our right element first
            for (int i = levelSize; i > 0; i--) {
                // traversing from levelSize 
                TreeNode *current = nodeQ.front();
                nodeQ.pop();
                
                // first node in the queue on this level is the right view based on how
                // we pushed them into the queue
                if (i == levelSize) {
                    result.push_back(current -> val);
                }
                
                // if children aren't null, push them into our queue
                if (current -> right != nullptr) {
                    nodeQ.push(current -> right);
                }
                
                if (current -> left != nullptr) {
                    nodeQ.push(current -> left);
                }
            }
        }
        
        return result;
    }
};