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
        if(!root){//if root is NULL
            return true;
        }
        if(root->val<=mini || root->val>=maxi){//if it doesnt satisfy the BST condition
            return false;
        }
        if(root->left==NULL && root->right==NULL){//Leaf node
            if(mp.count(root->val) && root!=node){//if the map has the subroot 
                // TreeNode*temp=mp[root->val];
                // root->left=temp->left;
                // root->right=temp->right;
                // mp.erase(temp->val);
                root=mp[root->val];// replace with it 
                mp.erase(root->val);//remove it
            }
        }
        return validate(root->left,mini,root->val,mp,node) && validate(root->right,root->val,maxi,mp,node);//check for both left and right
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>child;
        for(auto &tree:trees){//add the tree value and adress onto map
            mp[tree->val]=tree;
            if(tree->left){
                child.insert(tree->left->val);//add its child nodes onto set
            }
            if(tree->right){
                child.insert(tree->right->val);
            }
        }
        TreeNode*root=NULL;
        for(auto &tree:trees){//for finding root
            if(child.count(tree->val)==0){
                if(root!=NULL){//if two roots exist
                    return NULL;
                }
                root=tree;
            }
        }
        if(root==NULL){//if no root is found
            return NULL;
        }
        mp.erase(root->val);//remove the root from map
        if(!validate(root,LLONG_MIN,LLONG_MAX,mp,root)){//check if merging and bst is true or not
            return NULL;
        }
        if(!mp.empty()){//if empty or not
            return NULL;
        }
        return root;//return the final tree
    }
};