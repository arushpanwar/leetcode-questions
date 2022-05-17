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
    bool isBST(TreeNode* root){
        static TreeNode *prev=NULL;
        if(root){
            if(!isBST(root->left))return false;
            if(prev!=NULL&&prev->val>=root->val)return false;
            prev=root;
            return isBST(root->right);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};
