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
    ListNode *reverse(ListNode *curr, ListNode *prev){
        if(curr==NULL){
            return prev;
        }
        ListNode *fut=curr->next;
        curr->next=prev;
        return reverse(fut,curr);
    }
    bool isPalindrome(ListNode* head) {
        // first approach
        if(head->next==NULL){
            return true;
        }
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *curr=head, *prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr=reverse(curr,NULL);
        ListNode *head1=head, *head2=curr;
        while(head1){
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};