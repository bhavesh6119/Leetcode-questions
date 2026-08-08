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
class box{
    public:
    bool BST;
    int sum;
    int mini,maxi;
    box(){
        BST=1;
        sum=0;
        mini=INT_MAX;
        maxi=INT_MIN;
    }
};
    box* find(TreeNode*root,int &totalsum){
        if(!root){
            return new box();
        }
        box* lefthead=find(root->left,totalsum);
        box* righthead=find(root->right,totalsum);
        if(lefthead->BST && righthead->BST && lefthead->maxi < root->val && righthead->mini > root->val){
            box* head=new box();
            head->sum+=root->val+lefthead->sum+righthead->sum;
            head->mini=min(lefthead->mini,root->val);
            head->maxi=max(righthead->maxi,root->val);
            totalsum=max(totalsum,head->sum);
            return head;
        }else{
            lefthead->BST=0;
            return lefthead;
        }
    }
    int maxSumBST(TreeNode* root) {
        int totalsum=0;
        find(root,totalsum);
        return totalsum;
    }
};