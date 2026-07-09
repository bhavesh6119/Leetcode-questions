class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n,0);
        stack<int>st;
        // //brute force
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(t[j]>t[i]){
        //             ans[i]=j-i;
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //optmised approach
        for(int i=n-1;i>=0;i--){//moving from right to left
            while(!st.empty() && t[st.top()]<=t[i]){//till the top element is less than the current element pop the top 
                st.pop();
            }
            //here we didnt add s=any empty condition as in problem we have been given that for the temp if there is no highest on right side let it remain 0
            if(!st.empty()){//now when popping is done
            //which means the ith element is smaller than the top element 
                ans[i]=st.top()-i;//so we will subtract the indexes to get the count
            }
            st.push(i);//then again push the current element onto the stack 
        }
        return ans;
    }
};