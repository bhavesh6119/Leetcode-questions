class Solution {
public:
    int thirdMax(vector<int>& nums) {
       priority_queue<int,vector<int>,greater<int>>p;
       unordered_set<int>st;
       int ans=0;
       for(int i=0;i<nums.size();i++){
        if(st.count(nums[i])){
            continue;
        }
        st.insert(nums[i]);
        p.push(nums[i]);
        if(p.size()>3){
           p.pop();
        }
       }
       if(p.size()<3){
        int ans=p.top();
        while(p.size()>1){
            p.pop();
            ans=p.top();
        }
        return ans;
       }
       return p.top();
    }
};