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
    void inorder(TreeNode*root,vector<long long>&arr){
        if(!root){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    void inorderrecover(TreeNode*root,vector<long long>&arr,int&index){
        if(!root || index==arr.size()){
            return;
        }
        inorderrecover(root->left,arr,index);
        root->val=arr[index++];
        inorderrecover(root->right,arr,index);
    }
    void recoverTree(TreeNode* root) {
        vector<long long>arr;
        inorder(root,arr);
        int first=-1;
        int second=-1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                if(first==-1){
                    first=i;
                }
                second=i+1;
            }
        }
        swap(arr[first],arr[second]);
        int index=0;
        inorderrecover(root,arr,index);
    }
};