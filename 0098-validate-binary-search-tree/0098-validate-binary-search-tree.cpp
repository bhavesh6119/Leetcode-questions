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
// //with inorder function
//     void inorder(TreeNode*root,vector<int>&ans){
//         if(!root){
//             return;
//         }
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
    bool BST(TreeNode*root,long long& prev){
         if(!root){
            return 1;
        }
        bool l=BST(root->left,prev);
        if(l==0){
            return 0;
        }
        if(root->val<=prev){
            return 0;
        }
        prev=root->val;
        return BST(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        // vector<int>ans;
        // inorder(root,ans);
        // for(int i=1;i<ans.size();i++){
        //     if(ans[i]<=ans[i-1]){
        //         return 0;
        //     }
        // }
        // return 1;
        
        // without inorder function
        long long prev=LLONG_MIN;
        return BST(root,prev);
    }
};