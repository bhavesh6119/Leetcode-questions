class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=0;
        unordered_map<int,int>mp;
        int maxlen=0;
        while(end<n){
            mp[nums[end]]++;
            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }
            maxlen=max(maxlen,end-start+1);
            end++;
        }
        return maxlen;

    }
};