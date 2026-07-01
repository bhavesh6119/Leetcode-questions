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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode*temp=new ListNode(0);//creating a new list
      temp->next=head;
      ListNode*prev=temp;//pointing at temp node
      ListNode*curr=head;//pointing at head node
      while(curr){
        while(curr->next && curr->val == curr->next->val){//if curr->next exist check if the value of curr and curr->next are same if yes then increment curr
            curr=curr->next;//it reaches the last node which contains the duplicate
        }

        if(prev->next==curr){//if prev->next==curr means curr has not moves ahead so it means it is not a duplicate value 
            prev=prev->next;//so keep it and proceed to next node
        }else{//else if they are not equal then the curr has moved ahead so curr->next has unique value use it after the prev
            prev->next=curr->next;
        }
        curr=curr->next;//increment curr
      }
      return temp->next;//return the next node of dummy node
    }
};