class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        //we are traversing from left to right 
        for(int i=0;i<2*n;i++){//traversing the double of array meaning in circular
            while(!st.empty() && arr[st.top()]<arr[i%n]){//comparing the current element with thr top one 
                ans[st.top()]=arr[i%n];//till its smaller add the current element 
                st.pop();//and pop the top element 
            }
            st.push(i%n);//push the index 
        }
        return ans;
    }
};