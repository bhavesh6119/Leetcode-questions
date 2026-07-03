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
    ListNode* sortList(ListNode* head) {
        vector<int>ans;
        ListNode *curr=head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(curr){//while curr is present push its value onto the ans array
            ans.push_back(curr->val);
            curr=curr->next;
        }
        sort(ans.begin(),ans.end());//sort the array 
        curr=head;
        for(int i=0;i<ans.size();i++){//traverse on array and ll and replace the values
            curr->val=ans[i];
            curr=curr->next;
        }
        return head;
    }
};