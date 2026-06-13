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
    void dfs(Node* node, Node* clone_node, unordered_map<Node*, Node*> & mpp){
        for(Node* n : node->neighbors){
            if(mpp.find(n) == mpp.end()){
                Node* clone = new Node(n->val);
                mpp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone, mpp);
            }else{
                clone_node->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node* , Node*>mpp;
        mpp.clear();
        // clone the given node
        Node* clone_node = new Node(node->val);
        // clone its neighbours and recursively their neighbours
        mpp[node] = clone_node;
        dfs(node, clone_node, mpp);
        return clone_node;
    }
};
