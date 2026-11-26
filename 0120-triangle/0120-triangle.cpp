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
        vector<vector<int>>dp(m,vector<int>(m,0));

        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(up,diag);
            }
        }
        return dp[0][0];
    }
};