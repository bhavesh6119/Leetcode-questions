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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int count=0;
        // if(head==NULL && head->next==NULL){
        //     return NULL;
        // }
        while(temp!=NULL){//traversing temp until we reach the end adn counting no. of nodes 
            count++;
            temp=temp->next;
        }
        count-=n;//decreaing count by n so that we can know which node habe to deleted from the end
        if(count==0){//edge case as if the node deleted would be the first node 
            temp=head;
            head=head->next;
            delete temp;
        }else{//otherwise
            ListNode *curr=head,*prev=NULL;
            while(count--){//till count becomes zero traverse to the node that has to be deleted
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
        }
        return head;
    }
};