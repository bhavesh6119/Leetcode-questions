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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1st approach
        if(head==NULL || head->next==NULL){//edge case if only one node is present
            return head;
        }
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL){
            count++;//counting the number of nodes
            temp=temp->next;
        }
        k=k%count;//taking the exact number of rotations
        if(k==0){//if 0 no rotation to be made
            return head;
        }
        count-=k;//reducing count by k so that we can go to the exact node where we have to break the list
        ListNode *curr=head, *prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;//here list breaks 
        ListNode *tail=curr;
        while(tail->next!=NULL){//raversing on the other half of the list
            tail=tail->next;
        }
        tail->next=head;//connecting it to main list
        head=curr;//making the new head
        return head;
    }
};