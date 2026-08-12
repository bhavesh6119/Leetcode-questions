class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(right<n){
            mp[nums[right]]++;
            if(mp[nums[right]]<=k){
                ans=max(ans,right-left+1);
            }else{
               while(mp[nums[right]]>k){ 
                mp[nums[left]]--;
                left++;
               }
            }
            right++;
        }
        return ans;
    }
};