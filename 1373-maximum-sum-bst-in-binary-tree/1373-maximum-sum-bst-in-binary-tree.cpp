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
class box{//created a class
    public:
    bool BST;
    int sum;
    int mini,maxi;
    box(){//constructor
        BST=1;//if created then it is a BST
        sum=0;//in starting let it 0
        mini=INT_MAX;
        maxi=INT_MIN;
    }
};
    box* find(TreeNode*root,int &totalsum){
        if(!root){//if NULL
            return new box();//create new box
        }
        box* lefthead=find(root->left,totalsum);//find for left
        box* righthead=find(root->right,totalsum);//find for right
        if(lefthead->BST && righthead->BST && lefthead->maxi < root->val && righthead->mini > root->val){//if this condition satisfies then it is a binary search tree
            box* head=new box();//new box is created
            head->sum+=root->val+lefthead->sum+righthead->sum;//update the sum
            head->mini=min(lefthead->mini,root->val);//update the mini
            head->maxi=max(righthead->maxi,root->val);//update the maxi
            totalsum=max(totalsum,head->sum);//update the totalsum
            return head;//return the new head
        }else{
            lefthead->BST=0;//otherwise make it false
            return lefthead;
        }
    }
    int maxSumBST(TreeNode* root) {
        int totalsum=0;
        find(root,totalsum);//pass onto function
        return totalsum;
    }
};