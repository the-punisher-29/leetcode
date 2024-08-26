/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root==NULL) return res;
        posto(root,res);
        return res;
    }
private:
    void posto(Node* node,vector<int> &res){
        if(node==NULL) return;
        for(Node* child:node->children){
            posto(child,res);
        }
        res.push_back(node->val);
    }
};