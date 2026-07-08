class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        // vector<int>right(n,0);//right array to maintain the right smallest
        // vector<int>left(n,0);//left array to maintain the left smallest
        // stack<int>st;
        // int ans=0;//for maintaining the area
        // for(int i=0;i<n;i++){//first traversing left to right
        // //finding the right next right smallest at every index
        //     while(!st.empty() && h[st.top()]>h[i]){
        //         right[st.top()]=i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // //this we will do if we find no smallest
        // while(!st.empty()){
        //     right[st.top()]=n;//fill it with n
        //     st.pop();
        // }
        // for(int i=n-1;i>=0;i--){//traversing from right to left 
        // //finding the next left smallest for every index    
        //     while(!st.empty() && h[st.top()]>h[i]){
        //         left[st.top()]=i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // //this we will do if we found no amllest on left 
        // while(!st.empty()){
        //     left[st.top()]=-1;//fill it with -1
        //     st.pop();
        // }

        // for(int i=0;i<n;i++){//lastly traverse the arrays together and use that value to calculate the area 
        //     ans=max(ans,h[i]*(right[i]-left[i]-1));//we have to take the max area
        // }
        // return ans;

        //another optimised approach of solving it one go
        int ans=0;
        int index;
        stack<int>st;
        for(int i=0;i<n;i++){//traversing from keft to right
            while(!st.empty() && h[st.top()]>h[i]){
                index=st.top();//storing the index at top
                st.pop();//popping it
                if(!st.empty()){//if stack is not empty then the top elemnet is the next left smallest for index element
                    ans=max(ans,h[index]*(i-st.top()-1));//here i is the next right smallest for index element
                }else{//if stack is empty  then it means no nextx left smallest is there for index element
                    ans=max(ans,h[index]*i);//as right smallest is there 
                }
            }
            st.push(i);//push the current index
        }
        //same here till satck is empty
        while(!st.empty()){
            index=st.top();
            st.pop();
            if(!st.empty()){
                ans=max(ans,h[index]*(n-st.top()-1));//as n is the right smallest 
            }else{
                ans=max(ans,h[index]*n);
            }
        }
        return ans;
    }
};