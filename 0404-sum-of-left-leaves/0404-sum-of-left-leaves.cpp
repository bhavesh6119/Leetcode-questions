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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int sum=0;
        if(!root){
            return sum;
        }
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left){
            //checkingg if the left node is leaf or not    
                if(!temp->left->left && !temp->left->right){
                    sum+=temp->left->val;//if yes then add it
                }
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return sum;
    }
};