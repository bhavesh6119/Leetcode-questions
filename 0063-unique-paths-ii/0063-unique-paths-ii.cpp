class Solution {
public:
    int find(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(i>=0 && j>=0){
            if(arr[i][j]==1){
                return 0;
            }
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=find(i-1,j,arr,dp);
        int left=find(i,j-1,arr,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};