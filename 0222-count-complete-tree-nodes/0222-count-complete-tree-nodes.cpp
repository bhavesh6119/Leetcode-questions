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
    int leftheight(TreeNode* root){
        int depth=0;
        while(root){
            root= root->left;
            depth++;
        }
        return depth;
    }
    int rightheight(TreeNode* root){
        int depth=0;
        while(root){
            root= root->right;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = leftheight(root);
        int right = rightheight(root);

        if(left==right){
            return (1<<left)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};