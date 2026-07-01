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
        while(curr){//we have first counted the no. of nodes
            count++;
            curr=curr->next;
        }
        int n=count/k;//then divided it by the k as the nodes reversed should be a multiple of k
        ListNode *first=new ListNode(0);//initialised a LL with a dummy node
        first->next=head;
        head=first;
        while(first->next && n){//till first->next!=NULL or till n exist
            int x=k;
            ListNode *second=first->next;
            ListNode *prev=first;
            ListNode *curr=first->next;
            while(x && curr){//while they exist reverse the list
                ListNode *front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                x--;
            }
            first->next=prev;//replace the head 
            second->next=curr;//replace the end
            first=second;//move onto sesond group
            n--;//reducing the n 
        }
        first=head;
        head=head->next;
        delete first;//removing dummy node
        return head;
    }
};