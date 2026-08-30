class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++){
           if(nums[i]<nums[mini]){
            mini=i;
           }
           if(nums[i]>nums[maxi]){
            maxi=i;
           }
        }

        int left=min(mini,maxi);
        int right=max(mini,maxi);

        int count1 = right+1;
        int count2=  n-left;
        int count3= (left+1) + (n-right);

        return min({count1,count2,count3});
    }
};