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
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;//we created a temp node and added the value of next node to it
        node->val=temp->val;//then copied that value in current node
        node->next=temp->next;//then copied the address it contains 
        delete temp;//delted the temp node 
        //now the curr data is been replaced by the next one and next oe is deleted
    }
};