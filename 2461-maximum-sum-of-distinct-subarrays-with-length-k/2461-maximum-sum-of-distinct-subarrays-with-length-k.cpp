class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxsum=0;
        long long sum=0;
        int start=0;
        int end=0;
        long long size=0;
        unordered_map<int,int>mp;
        while(end<n){
            mp[nums[end]]++;
            sum+=nums[end];
            while(end-start+1 > k){
                mp[nums[start]]--;
                sum-=nums[start];
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            if((end-start)+1==k && mp.size()==k){
                maxsum=max(maxsum,sum);
            }
            end++;
        }
        return maxsum;
    }
};