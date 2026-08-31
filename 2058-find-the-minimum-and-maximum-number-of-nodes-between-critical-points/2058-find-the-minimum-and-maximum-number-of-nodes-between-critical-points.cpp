/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int first=-1;
    int last=-1;
    int mindistance=INT_MAX;
    int maxdistance=INT_MIN;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        int count=1;
        while(curr && curr->next){
            ListNode*fut=curr->next;
            if(prev && fut){
                if((curr->val > prev->val && curr->val > fut->val)||
                curr->val < prev->val && curr->val < fut->val){
                    if(first==-1){
                        first=count;
                        last=count;
                    }else {
                        mindistance=min(mindistance,count-last);
                        last=count;
                    }
                }
            }
            prev=curr;
            curr=fut;
            count++;
        }
        maxdistance=max(maxdistance,last-first);
        // return (mindistance==INT_MAX || maxdistance==INT_MIN) ? vector<int>{-1,-1} : vector<int>{mindistance,maxdistance};
        if(mindistance==INT_MAX){
            return {-1,-1};
        }
        return {mindistance,maxdistance};
    }

};