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
    int find(vector<int>&in,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* Tree(vector<int>&in, vector<int>&pre, int INstart,int INend,int index){
        if(INstart>INend){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[index]);
        int pos=find(in,pre[index],INstart,INend);
        root->left=Tree(in,pre,INstart,pos-1,index+1);
        root->right=Tree(in,pre,pos+1,INend,index+(pos-INstart)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int INstart=0;
        int INend=inorder.size()-1;
        int index=0;
        TreeNode* root=Tree(inorder,preorder,INstart,INend,index);
        return root;
    }
};