class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int start=0;
        int end=0;
        int product=1;
        while(end<n){
            product*=nums[end];
            while(product>=k && start<=end){
                product/=nums[start];
                start++;
            }
            total+=(end-start)+1;
            end++;
        }
        return total;
    }

};