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

// 10/4/2022 Clone Graph (Medium)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // if a initial node doesn't exist just return null
        if (node == nullptr) {
            return nullptr;
        }
        
        // initalize map to keep track of what copies we've made and queue for bfs traversal
        unordered_map<Node*,Node*> nodeMap;
        queue<Node*> nodeQueue;
        
        // begin traversal by pushing our initial node into the queue
        nodeQueue.push(node);
        // create our first copy and map it to our first initial node
        Node *copy = new Node(node -> val);
        nodeMap[node] = copy;
        
        // do bfs traversal until we've traversed all nodes
        while(!nodeQueue.empty()) {
            Node *current = nodeQueue.front(); // get our current node
            nodeQueue.pop();
            
            // iterate through the neighbors of our current node
            for (int i = 0; i < current -> neighbors.size(); i++) {
                Node *neighbor = current -> neighbors[i];
                // if we haven't made a copy for our current neighbor, we map the copy
                // and then push the neighbor into our queue because we still need to traverse it 
                if (nodeMap.find(neighbor) == nodeMap.end()) {
                    Node *copyNeighbor = new Node(neighbor -> val);
                    nodeMap[neighbor] = copyNeighbor;
                    nodeQueue.push(neighbor);
                }
                
                // for every iteration, we need to add the current neighbor to our current nodes copy's neighbor vector
                nodeMap[current] -> neighbors.push_back(nodeMap[neighbor]);
            }
        }
        
        return copy;
    }
};