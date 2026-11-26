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
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-100000));
        for(int i=0;i<n;i++){
            mini=min(mini,find(n-1,i,matrix,dp));
        }
        return mini;
    }
};