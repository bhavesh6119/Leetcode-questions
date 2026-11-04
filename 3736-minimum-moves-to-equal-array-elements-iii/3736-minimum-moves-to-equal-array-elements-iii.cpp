class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        int count=0;
        for(int i=0;i<n;i++){
            count+=abs(nums[i]-maxi);
        }

        return count;
    }
};