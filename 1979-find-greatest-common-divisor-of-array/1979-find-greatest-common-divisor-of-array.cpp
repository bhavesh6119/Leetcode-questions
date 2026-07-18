class Solution {
public:
    int findGCD(vector<int>& nums) {
        int lowest=INT_MAX;
        int highest=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            lowest=min(lowest,nums[i]);
            highest=max(highest,nums[i]);
        }
        int gcd=1;
        for(int i=2;i<=1000;i++){
            if(lowest%i==0 && highest%i==0){
                gcd=max(gcd,i);
            }
        }
        return gcd;
    }
};