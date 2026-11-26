class Solution {
public:
    int find(int i,int j,vector<vector<int>>&arr,vector<vector<int>>& dp){
        int n=arr.size();
        if(j<0 || j>=n){
            return 1e9;
        }
        if(i==0){
            return arr[i][j];
        }
        if(dp[i][j]!=-100000){
            return dp[i][j];
        }
        int up=arr[i][j]+find(i-1,j,arr,dp);
        int diagLeft=arr[i][j]+find(i-1,j-1,arr,dp);
        int diagRight=arr[i][j]+find(i-1,j+1,arr,dp);

        return dp[i][j]=min(up,min(diagLeft,diagRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-100000));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=dp[i-1][j];
                int diagLeft=INT_MAX,diagRight=INT_MAX;
                
                if(j>0){
                    diagLeft=dp[i-1][j-1];
                }
                if(j<n-1){
                    diagRight=dp[i-1][j+1];
                }

                dp[i][j]=matrix[i][j]+min(up,min(diagLeft,diagRight));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }

        return mini;
    }
};