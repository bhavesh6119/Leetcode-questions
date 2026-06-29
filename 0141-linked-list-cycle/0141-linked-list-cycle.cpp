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
    bool hasCycle(ListNode *head) {
        // // 1st approach
        // unordered_map<ListNode*,bool>visited;//making a map to store the adresses and marking them marked as we traverse
        // ListNode *curr=head;
        // while(curr!=NULL){
        //     if(visited[curr]==1){//if the adrress is already marked it means it is a loop
        //         return true;
        //     }
        //     visited[curr]=1;//make them marked
        //     curr=curr->next;
        // }
        // return false;

        // 2nd approach
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){//if they reach at same pos means they are in a loop
                return 1;
            }
        }
        return 0;
    }
};