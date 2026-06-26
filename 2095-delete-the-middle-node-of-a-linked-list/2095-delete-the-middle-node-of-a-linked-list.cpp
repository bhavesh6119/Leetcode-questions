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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head;//using slow pointer to reach the middle
        ListNode *fast=head;//fast is running on doubke speed when fast reaches end the slow is at the middle
        ListNode *prev=NULL;//tarcking the prev node of slow as we have to delete slow
        if(head->next==NULL){//edge case if only one node is there
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;//adding the adtress of the next node of slow to the prev so that the link doesnt break
        delete slow;//deleting slow

        return head;
    }
};