class Solution {
public:
    int find(int i,vector<int>&dp){
        if(i<=1){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=find(i-1,dp);
        int two=find(i-2,dp);

        return dp[i]=one+two;
    }
    int climbStairs(int m) {
        vector<int>dp(m+1,-1);
        int total=find(m,dp);
        return total;
    }
};