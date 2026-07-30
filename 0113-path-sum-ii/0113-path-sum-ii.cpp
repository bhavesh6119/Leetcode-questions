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
    void find(TreeNode*root,int sum,int target,vector<int>temp,vector<vector<int>>&ans){
        if(!root){
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        find(root->left,sum,target,temp,ans);
        find(root->right,sum,target,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        find(root,sum,targetSum,temp,ans);
        return ans;
    }
};