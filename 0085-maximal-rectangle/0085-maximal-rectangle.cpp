class Solution {
public:
    int rectangle(vector<int>& h){
        int n=h.size();
        int ans=0;
        int index;
        stack<int>st;
        for(int i=0;i<n;i++){//traversing from keft to right
            while(!st.empty() && h[st.top()]>=h[i]){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        if(matrix.empty()){
            return 0;
        }
        vector<int>height(col,0);//initailsing a height vector to store the heights of the ractangles
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){//traversing on matrix
            //for every row as base we calculate a height by traversing on columns
                if(matrix[i][j]=='0'){//if the col is 0 the the height is 0
                    height[j]=0;
                }else{//otherwise 1 will be there so we add 1
                    height[j]+=1;
                }
            }
           ans=max(ans,rectangle(height));//passing onto the rectangle function that calculates the max area
        }
        return ans;
    }
};