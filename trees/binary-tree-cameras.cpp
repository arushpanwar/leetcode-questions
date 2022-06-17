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
    int cam = 0;
    int minCameraCover(TreeNode* root) {
        return dfs(root)==0 ? cam+1 : cam;
    }
    int dfs(TreeNode* node) {
        if(node == NULL) return 1;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left == 0 || right == 0) {
            cam++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        else return 0;
        
    }
};
