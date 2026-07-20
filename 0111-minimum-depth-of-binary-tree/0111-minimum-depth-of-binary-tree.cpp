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
    int minDepth(TreeNode* root) {
        if(root==NULL){//if root is null then return 0
            return 0;
        }
        if(!root->left && !root->right){//if both right and left are null so return 1 which is the current node
            return 1;
        }
        if(!root->right){// if there is no right node
            return 1+minDepth(root->left);//so just exapand it to the left nodes and calculate the minimum depth
        }
        if(!root->left){// if there is np left node
           return 1+minDepth(root->right);
        }

        return 1+min(minDepth(root->left),minDepth(root->right));//if both left and right node are present
    }
};