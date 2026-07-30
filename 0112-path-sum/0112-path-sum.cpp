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
    bool find(TreeNode*root,int sum,int target){
        if(!root){
            return false;
        }
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==target){
                return true;
            }
            return false;
        }
        return find(root->left,sum,target) || find(root->right,sum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return find(root,sum,targetSum);
    }
};