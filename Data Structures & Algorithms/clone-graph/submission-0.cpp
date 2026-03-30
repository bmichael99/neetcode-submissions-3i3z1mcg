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
    unordered_map<Node*,Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        return DFS(node);
    }
    //when we reach a node, if it does not in the hashmap we create a copy.
    //we add all neighbors of the original to the copy, but we want to add copies of the neighbors not the original, if the neighbors already exist as in a copy has already been created, add the mapped copy instead of creating a new one.

    Node* DFS(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        if(nodeMap[node]){
            return nodeMap[node];
        }

        Node* newNode = new Node(node->val);
        nodeMap[node] = newNode;
        
        for(auto& neighbor : node->neighbors){
            Node* newNeighbor = DFS(neighbor);
            nodeMap[node]->neighbors.push_back(nodeMap[neighbor]);
        }

        return nodeMap[node];
    }
};