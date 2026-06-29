class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>arr(256,0);
        int first=0;
        int second=0;
        int length=0;
        while(second<s.size()){//travesring till the string size
            while(arr[s[second]]){//if the string has been marked and is positive then reduce all the string befor it till it and unmark it
                arr[s[first]]=0;
                first++;
            }
            arr[s[second]]=1;//now mark that char again and begin a new substring 
            length=max(length,second-first+1);//calculating length at every substring
            second++;
        }
        return length;//at last the length that remained
    }
};