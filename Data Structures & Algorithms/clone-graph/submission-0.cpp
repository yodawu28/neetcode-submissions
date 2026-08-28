/*
// Definition for a Node.
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
*/

class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, Node*> path;
    queue<Node*> q;

    void bfs(Node* node) {
        q.push(node);
        visited.insert(node->val);
        path[node->val] = new Node(node->val);
        
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                Node* front = q.front();
                q.pop();
                
                for (int i = 0; i < front->neighbors.size(); i++) {
                    Node* neighbor = front->neighbors[i];
                    auto it = path.find(neighbor->val);
                    if (it == path.end()) {
                        Node* newNeighbor = new Node(neighbor->val);
                        path[neighbor->val] = newNeighbor;
                        path[front->val]->neighbors.push_back(newNeighbor);
                    } else {
                        path[front->val]->neighbors.push_back(path[neighbor->val]);
                    }
                    
                    auto it1 = visited.find(neighbor->val);
                    if (it1 == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor->val);
                    }
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        bfs(node);
        
        return path[1];
    }
};
