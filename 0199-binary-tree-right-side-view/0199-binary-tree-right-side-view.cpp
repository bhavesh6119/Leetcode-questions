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
    void rightview(TreeNode* root,int level,vector<int>&ans){
        if(!root){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        rightview(root->right,level+1,ans);
        rightview(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        // //using queue
        // queue<TreeNode*>q;
        // q.push(root);
        // vector<int>ans;
        // if(!root){
        //     return ans;
        // }
        // while(!q.empty()){
        //     int n=q.size();
        //     ans.push_back(q.front()->val);//pushing the first value seen at a particular level
        //     while(n--){
        //         TreeNode*temp=q.front();//storing it in temp
        //         q.pop();//popping it
        //         if(temp->right){//then pushing its right to queue first
        //             q.push(temp->right);
        //         }
        //         if(temp->left){//then left
        //             q.push(temp->left);
        //         }
        //     }
        // }
        // return ans;
        
        //using recursion now
        vector<int>ans;
        rightview(root,0,ans);
        return ans;
    }
};