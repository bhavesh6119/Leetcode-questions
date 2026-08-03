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
class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushleft(TreeNode* node){//this is a function for pushing all the left values onto the stack
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    BSTIterator(TreeNode* root) {//it is initiator of pushleft
        pushleft(root);
    }
    
    int next() {//here we just give the val of stack.top() node
        TreeNode* curr=st.top();//store it
        st.pop();//pop it
        if(curr->right){//if its right exist 
            pushleft(curr->right);//push all the left side of its right
        }
        return curr->val;//return the stored value
    }
    
    bool hasNext() {//check if the stack is empty or not
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */