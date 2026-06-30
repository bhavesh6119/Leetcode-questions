class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n =arr.size();
        vector<int> freq(n+1,0);//creating a freq array 
        for(int num : arr){
            ++freq[min(num,n)];//storing the freq of elements at pos of min of the element or the n 
            //as n can be the highest max value that can in the array 
        }
        int ans=1;//initialsing answer with 1
        for(int num=2;num<=n;num++){//now traversing from 2 to n
            ans=min(ans+freq[num],num);//adding the freq of 2 to n to ans and replacing it with minimum of the added value or the curr num value 
            //so from here we can get the max ans
        }
        return ans;
    }
};