#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*,Node*> nodeMap;
        queue<Node*> nodeQueue;
        
        Node *copy = new Node(node -> val);
        nodeMap[node] = copy;
        
        nodeQueue.push(node);
        
        while (!nodeQueue.empty()) {
           // iterate through the neighbors of this current Node (not a copy)
            Node *currentNode = nodeQueue.front();
            nodeQueue.pop();
            
            for (int i = 0; i < currentNode -> neighbors.size(); i++) {
                // check if this current Neighbor is already mapped to a copy
                // if not then we need to create a copy, map it and push the neighbor into our queue
                
                // get neighbor of the node
                Node *neighbor = currentNode -> neighbors[i];
                
                // if we haven't mapped original neighbor to a copy, we create a copy and then push it into the queue
                if (nodeMap.find(neighbor) == nodeMap.end()) {
                    Node *newCopy = new Node(neighbor -> val);
                    nodeMap[neighbor] = newCopy;
                    nodeQueue.push(neighbor);
                }
                
                // afterwards we need to push the current neighbor into our current Node's copy's neighbor array
                nodeMap[currentNode] -> neighbors.push_back(nodeMap[neighbor]);
            }
        }
        
        return copy; // return beginning of the graph's copy
    }
};