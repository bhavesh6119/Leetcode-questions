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
    TreeNode* Tree(vector<int>&in, vector<int>&post, int INstart,int INend,int index){
        if(INstart>INend){
            return NULL;
        }
        TreeNode* root=new TreeNode(post[index]);
        int pos=find(in,post[index],INstart,INend);
        root->right=Tree(in,post,pos+1,INend,index-1);
        root->left=Tree(in,post,INstart,pos-1,index-(INend-pos)-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int INstart=0;
        int INend=inorder.size()-1;
        int index=postorder.size()-1;
        TreeNode* root=Tree(inorder,postorder,INstart,INend,index);
        return root;
    }
};