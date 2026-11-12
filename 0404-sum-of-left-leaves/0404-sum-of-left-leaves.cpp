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
    int leftleaves(TreeNode*root,bool isLeft){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return isLeft ? root->val : 0;
        }
        int left = leftleaves(root->left,true);
        int right = leftleaves(root->right,false);

        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = leftleaves(root,false);
        return sum;
    }
};