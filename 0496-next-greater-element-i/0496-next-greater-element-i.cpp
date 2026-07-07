class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute force solution
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n,-1);//make an array of size of num1 
        int k=0;//for traversing on num1
        while(k<n){//whike we can traverse
         for(int i=0;i<m;i++){//traverse on the main array 
            if(nums1[k]==nums2[i]){//check if it is equal or not 
                for(int j=i+1;j<m;j++){//if found then search from the right of the current index
                    if(nums2[j]>nums2[i]){
                        ans[k]=nums2[j];//if found the greater element just add it to ans array
                        break;//if greater element found
                    }
                }
                 break;//if the element is matched no need to search further in the nums2 array
            }
         }
         k++;//increment for array nums1
        }
        return ans;//result
    }
};