class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(k==n){
            for(auto x:nums){
                ans=max(x,ans);
            }
            return ans;
        }
        if(k==1){
            for(int i=0;i<n;i++){
                if(mp[nums[i]]==1){
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }
        if(mp[nums[0]]==1){
            ans=max(ans,nums[0]);
        }
        if(mp[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};