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
    void checkleaves1(TreeNode*root,vector<int>&ans1){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans1.push_back(root->val);
        }
        checkleaves1(root->left,ans1);
        checkleaves1(root->right,ans1);
    }
    void checkleaves2(TreeNode*root,vector<int>&ans2){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans2.push_back(root->val);
        }
        checkleaves2(root->left,ans2);
        checkleaves2(root->right,ans2);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        checkleaves1(root1,ans1);
        checkleaves2(root2,ans2);
        int n=ans1.size();
        int m=ans2.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }
        return true;
    }
};