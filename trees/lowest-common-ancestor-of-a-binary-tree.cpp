/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root,TreeNode* p){
        if(!root)return false;
        if(root==p)return true;
        return dfs(root->left,p)||dfs(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if((dfs(root->left,p)&&dfs(root->left,q)))return lowestCommonAncestor(root->left,p,q);
        if((dfs(root->right,p)&&dfs(root->right,q)))return lowestCommonAncestor(root->right,p,q);
        return root;
    }
  
  
  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(root==p||root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left&&right)return root;
        if(left)return left;
        return right;
    }
};
