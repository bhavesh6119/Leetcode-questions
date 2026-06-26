class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;//keeping the track of the subarrrays that has majority element as target
       for(int i=0;i<n;i++){//running an outer loop
        int targetcount=0;//maintaining the target count at each step 
        int othercount=0;//same with non target element
        for(int j=i;j<n;j++){
            if(nums[j]==target){//checking if it is the target element or not
                targetcount++;
            }else{
                othercount++;
            }
            if(targetcount>othercount){//comparing if it is greater we will increase our total that means we got our subarray with majority element as target
                total++;
            }
        }
       }
       return total;
    }
};