class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n =arr.size();
        //1st approach
        // vector<int> freq(n+1,0);//creating a freq array 
        // for(int num : arr){
        //     ++freq[min(num,n)];//storing the freq of elements at pos of min of the element or the n 
        //     //as n can be the highest max value that can in the array 
        // }
        // int ans=1;//initialsing answer with 1
        // for(int num=2;num<=n;num++){//now traversing from 2 to n
        //     ans=min(ans+freq[num],num);//adding the freq of 2 to n to ans and replacing it with minimum of the added value or the curr num value 
        //     //so from here we can get the max ans
        // }
        // return ans;

        //second approach
        sort(arr.begin(),arr.end());//sorting the array
        int maxEl=-1;//initialising max with -1
        for(int i=0;i<n;i++){//traversing the arr
            if(i==0){
                arr[0]=1;
            }else if(abs(arr[i]-arr[i-1])>1){//if it satisfies
                arr[i]=arr[i-1]+1;//then we just replace it with this
            }
                maxEl=max(maxEl,arr[i]);//update the max                
        }
        return maxEl;
    }
};