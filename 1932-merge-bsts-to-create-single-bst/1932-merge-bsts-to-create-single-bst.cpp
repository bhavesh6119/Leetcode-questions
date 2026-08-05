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
    bool validate(TreeNode*&root,long long mini,long long maxi,unordered_map<int,TreeNode*>&mp,TreeNode*node){
        if(!root){
            return true;
        }
        if(root->val<=mini || root->val>=maxi){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(mp.count(root->val) && root!=node){
                // TreeNode*temp=mp[root->val];
                // root->left=temp->left;
                // root->right=temp->right;
                // mp.erase(temp->val);
                root=mp[root->val];
                mp.erase(root->val);
            }
        }
        return validate(root->left,mini,root->val,mp,node) && validate(root->right,root->val,maxi,mp,node);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>child;
        for(auto &tree:trees){
            mp[tree->val]=tree;
            if(tree->left){
                child.insert(tree->left->val);
            }
            if(tree->right){
                child.insert(tree->right->val);
            }
        }
        TreeNode*root=NULL;
        for(auto &tree:trees){
            if(child.count(tree->val)==0){
                if(root!=NULL){
                    return NULL;
                }
                root=tree;
            }
        }
        if(root==NULL){
            return NULL;
        }
        mp.erase(root->val);
        if(!validate(root,LLONG_MIN,LLONG_MAX,mp,root)){
            return NULL;
        }
        if(!mp.empty()){
            return NULL;
        }
        return root;
    }
};