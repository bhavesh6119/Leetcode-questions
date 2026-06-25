class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
       
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                nums[i]=1;
            }else{
                nums[i]=-1;
            }
        }
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                total++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]-nums[i-1]>0){
                    total++;
                }
            }
        }
        return total;
    }
};