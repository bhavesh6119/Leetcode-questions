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
    bool parents(TreeNode* root,int x,int y){
        if(root==NULL){
            return 0;
        }
        if(root->left && root->right){//if both right and left exist
        if(root->left->val==x && root->right->val==y){//check if any parent has right and left value same as given 
            return 1;
        }
        if(root->left->val==y && root->right->val==x){//same here
            return 1;
        }
        }
        return parents(root->left,x,y) || parents(root->right,x,y);//otherwise return the or of the left and right
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int level=0;
        int l1=-1;
        int l2=-1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();//storing the size of current q
            while(n--){
                TreeNode *temp=q.front();//storing the front node address
                q.pop();
                if(temp->val==x){//now checking if the val matches the given node or not
                    l1=level;//mark the level
                }
                if(temp->val==y){//same here
                    l2=level;
                }
                if(temp->left){//normal queue level wise traversal
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;//increse the level after completely iterating the size of q
            if(l1!=l2){
                return 0;//if they are not on equal levels
            }
            if(l1!=-1 || l2!=-1){//if they have got their level assigned 
                break;
            }
        }
        return !parents(root,x,y);//return inverse of this function
    }
};