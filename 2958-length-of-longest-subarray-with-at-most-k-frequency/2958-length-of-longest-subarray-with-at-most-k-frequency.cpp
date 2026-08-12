class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        //using two pointer approach
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int>mp;//storing the frequency of the elements
        while(right<n){//till right!=sizeof array
            mp[nums[right]]++;//increment freq
            if(mp[nums[right]]<=k){//if freq is less than or equal to k
                ans=max(ans,right-left+1);//update the ans
            }else{
               while(mp[nums[right]]>k){ //if at any point it becomes greater
                mp[nums[left]]--;//ruduce the freq of the first element of subarray 
                left++;//reduce subarray size
               }
            }
            right++;//otherwise increase the subarray size
        }
        return ans;
    }
};