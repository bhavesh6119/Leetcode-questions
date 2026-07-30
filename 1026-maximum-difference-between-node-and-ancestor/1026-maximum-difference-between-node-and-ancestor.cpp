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
    int findmaxdiff(TreeNode*root,int maxv,int minv){
        if(!root){
            return abs(maxv-minv);
        }
        minv=min(minv,root->val);
        maxv=max(maxv,root->val);
        int l=findmaxdiff(root->left,maxv,minv);
        int r=findmaxdiff(root->right,maxv,minv);

        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findmaxdiff(root,root->val,root->val);
    }
};