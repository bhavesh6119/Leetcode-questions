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
            if(d.empty()){//if empty then directly push
                d.push_back(i);
            }else{
                while(!d.empty() &&  nums[i]>nums[d.back()]){//else if the last element is smaller then pop it
                    d.pop_back();
                }
                d.push_back(i);//push the current index
            }
        }
        for(int i=k-1;i<n;i++){
            while(!d.empty() && nums[i]>nums[d.back()]){//similarly do here 
                d.pop_back();
            }
            d.push_back(i);//push the current index
            if(d.front()<=i-k){//now if the front is out of window bound
                d.pop_front();//pop it
            }
            ans.push_back(nums[d.front()]);//push the element at front as it is the greatest
        }
        return ans;
    }
};