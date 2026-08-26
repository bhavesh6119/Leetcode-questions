class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefixsum=0;
        int total=0;
        int rem=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            rem= prefixsum % k;
            if(rem<0){
                rem = k + rem;
            }
            if(mp.count(rem)){
                total+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]++;
            }
        }
        return total;
    }
};