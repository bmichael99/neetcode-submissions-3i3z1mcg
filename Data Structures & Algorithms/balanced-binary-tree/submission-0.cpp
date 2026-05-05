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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        isBalancedHelper(root);
        return balanced;
    }

    int isBalancedHelper(TreeNode* root) {
        if(root == nullptr){
          return 0;
        }

        int leftDepth = isBalancedHelper(root->left);
        int rightDepth = isBalancedHelper(root->right);

        if(abs(leftDepth - rightDepth) > 1){
          balanced = false;
        }

        return 1 + max(leftDepth,rightDepth);
    }
};