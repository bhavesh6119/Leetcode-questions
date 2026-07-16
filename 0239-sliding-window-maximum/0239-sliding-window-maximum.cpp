class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // //brute force approach
        // vector<int>ans;
        // int n=nums.size();
        // for(int i=0;i<=n-k;i++){
        //     int total=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         total=max(total,nums[j]);
        //     }
        //     ans.push_back(total);
        // }
        // return ans;

        //optimised approach 
        vector<int>ans;
        int n=nums.size();
        deque<int>d;
        for(int i=0;i<k-1;i++){
            if(d.empty()){
                d.push_back(i);
            }else{
                while(!d.empty() &&  nums[i]>nums[d.back()]){
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        for(int i=k-1;i<n;i++){
            while(!d.empty() && nums[i]>nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
            if(d.front()<=i-k){
                d.pop_front();
            }
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};