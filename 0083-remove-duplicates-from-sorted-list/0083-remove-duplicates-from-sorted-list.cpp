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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){//edge case
            return head;
        }
        ListNode*curr=head->next;//going to head next
        ListNode*prev=head;//at head
        while(curr){
            if(curr->val==prev->val){//to compare the values if they are eqaul then delete curr
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};