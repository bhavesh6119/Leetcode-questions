class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n= nums.size();
        long long product=1;
        long long sum=0;
        int start=0;
        int end=0;
        long long total=0;
        while(end<n){
            sum+=nums[end];
            product=sum*((end-start)+1);
            while(product>=k && start<=end){
                sum-=nums[start];
                start++;
                product=sum*((end-start)+1);
            }
            total+=(end-start)+1;
            end++;
        }
        return total;
    }
};