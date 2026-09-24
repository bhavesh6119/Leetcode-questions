class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int digit=nums[i];
            int sum=0;
            while(digit){
             sum+=digit%10;
             digit/=10;
            }
            if(sum==i){
                mini=min(mini,i);
            }
        }
        return mini==INT_MAX ? -1 : mini;
    }
};