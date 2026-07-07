class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n,-1);
        int k=0;
        while(k<n){
         for(int i=0;i<m;i++){
            if(nums1[k]==nums2[i]){
                for(int j=i+1;j<m;j++){
                    if(nums2[j]>nums2[i]){
                        ans[k]=nums2[j];
                        break;
                    }
                }
                   break;
            }
         }
         k++;
        }
        return ans;
    }
};