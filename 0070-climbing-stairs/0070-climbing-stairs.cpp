class Solution {
public:
    int find(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left=find(n-1,dp);
        int right=find(n-2,dp);
        return dp[n]=left+right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int total=find(n,dp);
        return total;
    }
};