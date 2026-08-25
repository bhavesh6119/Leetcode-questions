class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<=100;i++){
            if(!mp.count(k*i)){
                return k*i;
            }
        }
        return ((100/k)+1)*k;
    }
};