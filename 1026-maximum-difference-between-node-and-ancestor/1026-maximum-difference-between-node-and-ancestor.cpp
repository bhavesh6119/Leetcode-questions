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
    int maxdiff;
    void findmaxdifference(TreeNode* root,TreeNode*child){
        if(!root || !child){
            return;
        }
        maxdiff=max(maxdiff,abs(root->val-child->val));
        findmaxdifference(root,child->left);
        findmaxdifference(root,child->right);
    }
    void findmaxdiff(TreeNode* root){
        if(!root){
            return;
        }
        findmaxdifference(root,root->left);
        findmaxdifference(root,root->right);

        findmaxdiff(root->left);
        findmaxdiff(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxdiff=-1;
        findmaxdiff(root);
        return maxdiff;
    }
};