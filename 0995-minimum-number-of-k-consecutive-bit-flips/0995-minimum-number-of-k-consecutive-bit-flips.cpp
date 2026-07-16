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
        for(int i=0;i<n;i++){//iterate on the nums array
            if(!q.empty() && q.front()<i){//if q is not empty and front is less than current index
                q.pop();//pop it
            }
            if(q.size()%2==nums[i]){//otherwise if this condition is satisfied then we have to flip
                if(i+k-1>=n){//if exceeds the window size
                    return -1;
                }else{
                    q.push(i+k-1);//push the last index of the window
                    flips++;//increase the flips
                }
            }
            //here size of q determines that how many flips have been made until the current index 
            //and if the size is odd and element is also 1 then we have to flip
            //if the size is even and element is also 0 then we have to flip 
            //as odd%2==1 -> 1 flipped odd times turn 0 so here we flip
            //similarly even%2==0 -> 0 flipped even times turn 0 so here we flip again
        }
        return flips;
    }
};