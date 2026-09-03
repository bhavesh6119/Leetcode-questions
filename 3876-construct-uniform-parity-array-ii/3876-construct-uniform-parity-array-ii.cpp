class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int oddcount=0;
        int evencount=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                evencount++;
            }else{
                oddcount++;
            }
            mini=min(mini,nums[i]);
        }
        if(mini%2==0 && evencount!=n){
            return 0;
        }
        return 1;
    }
};