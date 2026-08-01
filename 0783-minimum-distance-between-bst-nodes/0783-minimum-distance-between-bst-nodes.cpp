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
    void BSTdiff(TreeNode*root,int&ans,int&prev){
        if(!root){
            return;
        }
        BSTdiff(root->left,ans,prev);
        if(prev!=INT_MIN){
            ans=min(ans,root->val-prev);
        }
        prev=root->val;
        BSTdiff(root->right,ans,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        BSTdiff(root,ans,prev);
        return ans;
    }
};