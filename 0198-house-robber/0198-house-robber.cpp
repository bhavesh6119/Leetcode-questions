class Solution {
public:
    int find(int index,vector<int>&arr,vector<int>&dp){
        if(index==0){
            return arr[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick=arr[index]+find(index-2,arr,dp);
        int notpick=0+find(index-1,arr,dp);

        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int total=find(n-1,nums,dp);
        return total;
    }
};