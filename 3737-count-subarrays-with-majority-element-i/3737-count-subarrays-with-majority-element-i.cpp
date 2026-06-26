class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
       for(int i=0;i<n;i++){
        int targetcount=0;
        int othercount=0;
        for(int j=i;j<n;j++){
            if(nums[j]==target){
                targetcount++;
            }else{
                othercount++;
            }
            if(targetcount>othercount){
                total++;
            }
        }
       }
       return total;
    }
};