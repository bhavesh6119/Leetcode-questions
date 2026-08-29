class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=0;
        int total=0;
        unordered_map<int,int>mp;
        while(end<n){
            mp[nums[end]]++;
            while(mp.size()>k){
                mp[nums[start]]--;
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            total+=end-start+1;
            end++;
        }

        start=0;
        end=0;
        mp.clear();
        k--;
        while(end<n){
            mp[nums[end]]++;
            while(mp.size()>k){
                mp[nums[start]]--;
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            total-=end-start+1;
            end++;
        }
        return total;
    }
};