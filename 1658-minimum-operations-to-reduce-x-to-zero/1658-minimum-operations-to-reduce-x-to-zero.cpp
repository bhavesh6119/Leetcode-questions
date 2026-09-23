class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int start=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(x>total){
            return -1;
        }
        int find=total-x;
        if(find==0){
            return n;
        }
        int sum=0;
        int maxi=0;
        for(int end=0;end<n;end++){
            sum+=nums[end];
            while(sum>find){
                sum-=nums[start];
                start++;
            }
            if(sum==find){
                maxi=max(maxi,end-start+1);
            }
        }
        if(maxi==0){
            return -1;
        }
        return n-maxi;
    }
};