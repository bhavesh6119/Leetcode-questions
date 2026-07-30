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
    int count(TreeNode*root){
        if(!root){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
    bool dfs(TreeNode*root,int i,int total){
        if(!root){
            return true;
        }
        if(i>total){
            return false;
        }
        return dfs(root->left,2*i,total) && dfs(root->right,2*i+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        // //BFS
        // queue<TreeNode*>q;
        // q.push(root);
        // bool past=false;
        // while(!q.empty()){
        //     TreeNode* temp=q.front();
        //     q.pop();
        //     if(temp==NULL){
        //         past=true;
        //     }else{
        //         if(past==true){
        //             return false;
        //         }
        //         q.push(temp->left);
        //         q.push(temp->right);
        //     }
        // }
        // return true;

        //DFS
        int TotalNodes=count(root);
        int i=1;
        return dfs(root,i,TotalNodes);
    }
};