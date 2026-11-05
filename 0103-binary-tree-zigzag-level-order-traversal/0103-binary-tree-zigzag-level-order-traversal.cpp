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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root){
            return {};
        }
        q.push(root);
        bool LeftToRight=1;
        while(!q.empty()){
            vector<int>ans1;
            int n=q.size();
            stack<int>st;
            while(n--){
                TreeNode* temp= q.front();
                q.pop();
                if(LeftToRight){
                    ans1.push_back(temp->val);
                }else{
                    st.push(temp->val);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            while(!st.empty()){
                ans1.push_back(st.top());
                st.pop();
            }
            ans.push_back(ans1);
            LeftToRight = !LeftToRight;
        }
        return ans;
    }
};