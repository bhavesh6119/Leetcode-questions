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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        int n=count/k;
        ListNode *first=new ListNode(0);
        first->next=head;
        head=first;
        while(first->next && n){
            int x=k;
            ListNode *second=first->next;
            ListNode *prev=first;
            ListNode *curr=first->next;
            while(x && curr){
                ListNode *front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                x--;
            }
            first->next=prev;
            second->next=curr;
            first=second;
            n--;
        }
        first=head;
        head=head->next;
        delete first;
        return head;
    }
};