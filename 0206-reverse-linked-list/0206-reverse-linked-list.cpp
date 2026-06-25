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
    ListNode *reverse(ListNode *curr,ListNode *prev){
        if(curr==NULL){//when curr becomes null means it is out bound then only prev remains so we return the prev
            return prev;
        }
        ListNode *fut=curr->next;//storing the next node in fut
        curr->next=prev;//adding the address of the prev to the curr->next
        return reverse(fut,curr);//passing the new curr and prev
    }
    ListNode* reverseList(ListNode* head) {
        // //1st approach
        // vector<int>ans;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     ans.push_back(temp->val);//here we are traversing the list and storing the values onto the ans array
        //     temp=temp->next;
        // }
        // int i=ans.size()-1;//then traversing from last index of the ans array to get the values and replace them in the list
        // temp=head;
        // while(temp!=NULL){
        //     temp->val=ans[i];
        //     i--;
        //     temp=temp->next;
        // }

        // // 2nd approach
        //here we have created 3 pointers and while traversing upadting them side by side
        // ListNode *curr=head, *prev=NULL, *fut=NULL;
        // while(curr!=NULL){
        //     fut=curr->next;//adding the next node to fut
        //     curr->next=prev;//adding the prev address to curr
        //     prev=curr;//making curr the prev
        //     curr=fut;//updating curr as fut
        // }
        // head=prev;//at last the remaining is the prev so add it into head

        // 3rd approach Recursion
        head=reverse(head,NULL);
        return head;
    }
};