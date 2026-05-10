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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      //naive: check if all subtrees from root match subRoot.
      //optimal?: if a node equals the root of subRoot, check if this subtree equals subRoot
      if(root == nullptr || subRoot == nullptr){
        return false;
      }

      if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
        return true;
      }

      if(root->val == subRoot->val){
        return isSameTree(root,subRoot);
      }

      return false;
  }

  bool isSameTree(TreeNode* p, TreeNode* q) {
    if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)){
        return false;
    }
    if(p == nullptr && q == nullptr){
            return true;
    }
    if(p->val != q->val){
        return false;
    }

    if(isSameTree(p->left, q->left) && isSameTree(p->right,q->right)){
        return true;
    }

    return false;
  }
};