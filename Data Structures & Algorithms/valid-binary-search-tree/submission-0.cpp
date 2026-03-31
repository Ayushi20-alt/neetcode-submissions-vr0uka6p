/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // range me when i will go to left , right range ka part update hoga
        // and vice versa
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode* root, int min, int max){
        if(root == NULL) return true; 
        if(root->val >= max || root->val <= min) return false;
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
};
