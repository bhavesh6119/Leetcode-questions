class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>mp(3,0);//made a frequency map
        int n=s.size();
        int total=0;
        int j=0;
        int i=0;
        while(j<n){//till j<n
            char c=s[j];//we traverse to the string 
            mp[c-'a']++;//mark the corresponding index on map

            while(mp[0]>0 && mp[1]>0 && mp[2]>0){//if this is true that is if a,b,c are all present 
                total+=n-j;//add all the substrings that is after j all will contain the a,b,c so we just take a difference of total size with j to get the no. of strings that contain a,b,c

                mp[s[i]-'a']--;//slide the window ahead before that unmark the ith char  
                i++;//then proceed to next char
            }
            j++;//it will increase the size of window until the condition is satisfied 
        }
        return total;
    }
};