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
        if(root->left && root->right){
        if(root->left->val==x && root->right->val==y){
            return 1;
        }
        if(root->left->val==y && root->right->val==x){
            return 1;
        }
        }
        return parents(root->left,x,y) || parents(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int level=0;
        int l1=-1;
        int l2=-1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->val==x){
                    l1=level;
                }
                if(temp->val==y){
                    l2=level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
            if(l1!=l2){
                return 0;
            }
            if(l1!=-1 || l2!=-1){
                break;
            }
        }
        return !parents(root,x,y);
    }
};