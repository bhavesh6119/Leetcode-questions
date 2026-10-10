// bool comp(vector<int>a,vector<int>b){
//     return a[0]<b[0];
// }
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& task) {
        int n=task.size();
        for(int i=0;i<n;i++){
            task[i].push_back(i);
        }
        sort(task.begin(),task.end());
        
        long long timer=task[0][0];
        vector<int>ans;
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        while(i<n || !p.empty()){
            while(i<n && task[i][0]<=timer){
                p.push({task[i][1],task[i][2]});
                i++;
            }

            if(p.empty()){
                timer=task[i][0];
            }

            else{
                timer+=p.top().first;
                ans.push_back(p.top().second);
                p.pop();
            }
        }
        return ans;
    }
};