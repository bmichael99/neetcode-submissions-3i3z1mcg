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
    int myMax = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeHelper(root);
        return myMax;
    }

    int diameterOfBinaryTreeHelper(TreeNode* root){
      //largest diameter, is the largest left depth + right depth from current node.
        if(root == nullptr){
          return 0;
        }
        
        int leftDepth = diameterOfBinaryTreeHelper(root->left);
        int rightDepth = diameterOfBinaryTreeHelper(root->right);

        myMax = max(myMax, leftDepth+rightDepth);

        return 1 + max(leftDepth,rightDepth);
    }
};