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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int total=find(m-1,n-1,obstacleGrid,dp);
        return total;
    }
};