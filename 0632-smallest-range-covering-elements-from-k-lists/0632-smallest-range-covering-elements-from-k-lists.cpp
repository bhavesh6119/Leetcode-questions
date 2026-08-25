class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p;
        int mini;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            p.push(make_pair(nums[i][0],make_pair(i,0)));
            maxi=max(maxi,nums[i][0]);
        }
        vector<int>ans(2);
        mini=p.top().first;
        ans[0]=mini;
        ans[1]=maxi;

        pair<int,pair<int,int>>temp;
        int row,col;
        while(p.size()==n){
            temp=p.top();
            p.pop();
            row=temp.second.first;
            col=temp.second.second;

            if(col+1<nums[row].size()){
                col++;
                p.push(make_pair(nums[row][col],make_pair(row,col)));
                maxi=max(maxi,nums[row][col]);
                mini=p.top().first;
                
                if(maxi-mini < ans[1]-ans[0]){
                    ans[0]=mini;
                    ans[1]=maxi;
                }
            }
        }
        return ans;
    }
};