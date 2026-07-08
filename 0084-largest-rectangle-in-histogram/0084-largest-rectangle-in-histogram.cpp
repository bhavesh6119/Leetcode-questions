class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>h[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            right[st.top()]=n;
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }

        for(int i=0;i<n;i++){
            ans=max(ans,h[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};