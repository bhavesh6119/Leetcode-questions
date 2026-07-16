class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        //brute force
        // int n=nums.size();
        // int flip=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         if(i+k-1>=n){
        //             return -1;
        //         }
        //         for(int j=i;j<i+k;j++){
        //             nums[j]=!nums[j];
        //         }
        //         flip++;
        //     }
        // }
        // return flip;

        //optimised approach
        int n=nums.size();
        int flips=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front()<i){
                q.pop();
            }
            if(q.size()%2==nums[i]){
                if(i+k-1>=n){
                    return -1;
                }else{
                    q.push(i+k-1);
                    flips++;
                }
            }
        }
        return flips;
    }
};