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
    bool isLeaf(TreeNode* root){
        return (root->left==NULL&&root->right==NULL);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        if((root->left!=NULL)){
            if(isLeaf(root->left))ans+=root->left->val;
            else ans+=sumOfLeftLeaves(root->left);
        }
        if(root->right!=NULL){
            if(!isLeaf(root->right))ans+=sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};
