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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool>visited;
        ListNode *curr=head;
        while(curr!=NULL){
            if(visited[curr]==1){//if it is present in the map
                return curr;//so return the address of the node from where loop begins
            }
            visited[curr]=1;//mark it visited
            curr=curr->next;
        }
        return NULL;//otherwise NULL
    }
};