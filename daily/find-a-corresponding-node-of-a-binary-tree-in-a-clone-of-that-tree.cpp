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
    bool dfs(TreeNode* root,int value){
        if(!root)return false;
        if(root->val==value)return true;
        return dfs(root->left,value)||dfs(root->right,value);
    }
    TreeNode* getTarget(TreeNode* root,int value){
        if(root->val==value)return root;
        if(dfs(root->left,value))return getTarget(root->left,value);
        return getTarget(root->right,value);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)return target;
        int value=target->val;
        return getTarget(cloned,value);
    }
    
    //smaller dfs code
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original||original==target)return cloned;
        TreeNode* ans=getTargetCopy(original->left,cloned->left,target);
        if(ans)return ans;
        return getTargetCopy(original->right,cloned->right,target);
    }
};
