/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool>visited;
        ListNode *curr=headB;
        while(curr!=NULL){//first marking all the nodes of B list
            visited[curr]=1;
            curr=curr->next;
        }
        ListNode *curr2=headA;
        while(curr2!=NULL){//then traversing on the A list and checking if any of the node matches
            if(visited[curr2]==1){//if matches return that node 
                return curr2;
            }
            visited[curr]=1;//otherwise mark the nodes of A
            curr2=curr2->next;
        }
        return 0;
    }
};