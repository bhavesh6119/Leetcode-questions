class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixmax(n,0);
        vector<int>suffixmin(n,0);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixmax[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            suffixmin[i]=mini;
        }
        for(int i=0;i<n;i++){
            if((prefixmax[i]-suffixmin[i])<=k){
                return i;
            }
        }
        return -1;
    }
};