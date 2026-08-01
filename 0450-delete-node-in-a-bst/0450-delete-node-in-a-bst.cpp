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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){//base case
            return NULL;
        }
        if(root->val > key){//got to left
            root->left=deleteNode(root->left,key);
            return root;
        }
        if(root->val < key){//go to right
            root->right=deleteNode(root->right,key);
        }
        else{//if target is found
            if(!root->left && !root->right){//if it is a leaf node
                delete root;
                return NULL;
            }else if(!root->right){//if it left exist
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }else if(!root->left){//if its right exist
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }else{//if left and right both exist
                TreeNode*child=root->left;//go to left side
                TreeNode*parent=root;//make it root
                while(child->right){//go to extreme right to get greater element
                    parent=child;
                    child=child->right;
                }
                if(root!=parent){//if the right is present 
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }else{//if there is no right 
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
        }
        return root;//return the root 
    }
};