class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int cumsum=0;
        long long validleftpoints=0;
        long long result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                validleftpoints+=mp[cumsum];
                cumsum+=1;
            }else{
                cumsum-=1;
                validleftpoints-=mp[cumsum];
            }
            mp[cumsum]+=1;
            result+=validleftpoints;
        }
        return result;
    }
};