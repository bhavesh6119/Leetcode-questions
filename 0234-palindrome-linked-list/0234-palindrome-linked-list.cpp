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
    ListNode *reverse(ListNode *curr, ListNode *prev){//recursion for reversing the other half of the list
        if(curr==NULL){
            return prev;
        }
        ListNode *fut=curr->next;
        curr->next=prev;
        return reverse(fut,curr);
    }
    bool isPalindrome(ListNode* head) {
        // // first approach
        // if(head->next==NULL){//edge case if only one node is present
        //     return true;
        // }
        // ListNode *temp=head;
        // int count=0;
        // while(temp!=NULL){
        //     count++;//counting the number of nodes
        //     temp=temp->next;
        // }
        // count/=2;//dividing it by 2 so that break the list in half
        // ListNode *curr=head, *prev=NULL;
        // while(count--){//for the first half 
        //     prev=curr;
        //     curr=curr->next;
        // }
        // prev->next=NULL;
        // curr=reverse(curr,NULL);//for second half reversing it to check palindrome
        // //just normal algo for checking palindrome
        // ListNode *head1=head, *head2=curr;
        // while(head1){
        //     if(head1->val != head2->val){
        //         return false;
        //     }
        //     head1=head1->next;
        //     head2=head2->next;
        // }
        // return true;

        //second approach
        vector<int>ans;
        ListNode *temp=head;
        while(temp!=NULL){//just adding the values of nodes to an array
            ans.push_back(temp->val);
            temp=temp->next;
        }
        //applying two pointers approach to check palindrome in array
        int start=0;
        int end=ans.size()-1;
        while(start<=end){
            if(ans[start]!=ans[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};