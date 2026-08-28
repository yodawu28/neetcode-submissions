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

    void dfs(Node* node) {
        Node* newNode = new Node(node->val);
        visited.insert(node->val);
        path[node->val] = newNode;
        
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* neighbor = node->neighbors[i];
            auto it = visited.find(neighbor->val);
            if (it == visited.end()) {
                dfs(neighbor);
            }
            newNode->neighbors.push_back(path[neighbor->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        path.clear();
        visited.clear();

        dfs(node);

        return path[1];
    }
};
