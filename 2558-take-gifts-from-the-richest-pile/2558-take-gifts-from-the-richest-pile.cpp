class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<long long>p;
        for(int i=0;i<n;i++){
            p.push(gifts[i]);
        }
        while(k && (!p.empty())){
            int x=p.top();
            if(sqrt(x)){
                p.push(sqrt(x));
            }
            p.pop();
            k--;
        }
        long long ans=0;
        while(!p.empty()){
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};