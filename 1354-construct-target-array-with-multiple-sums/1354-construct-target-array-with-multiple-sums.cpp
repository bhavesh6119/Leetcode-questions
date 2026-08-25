class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long long sum=0;
        priority_queue<long long>p;
        for(int i=0;i<n;i++){
            p.push(target[i]);
            sum+=target[i];
        }
        long long maxi,rem_sum,element;
        while(p.top()!=1){
            maxi=p.top();
            p.pop();
            rem_sum=sum-maxi;
            if(rem_sum<=0 || rem_sum>=maxi){
                return 0;
            }
            element=maxi % rem_sum;
            if(element==0){
                if(rem_sum!=1){
                    return 0;
                }else{
                    return 1;
                }
            }
            sum=rem_sum+element;
            p.push(element);
        }
        return 1;
    }
};