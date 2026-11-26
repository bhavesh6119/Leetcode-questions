class Solution {
public:
    int find(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
        int n=arr.size();
        if(i==n-1){
            return arr[n-1][j];
        }
        if(dp[i][j]!=-100000){
            return dp[i][j];
        }
        int down=arr[i][j]+find(i+1,j,arr,dp);
        int diag=arr[i][j]+find(i+1,j+1,arr,dp);

        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-100000));
        int total=find(0,0,triangle,dp);
        return total;
    }
};