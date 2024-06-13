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
    int length(ListNode*&head){
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=length(head);
        if(head==NULL || head->next==NULL || len<k){
            return head;
        }


        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nextNode=curr->next;
        int pos=0;
        while(pos<k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            pos++;
        }
        ListNode*recursionKaAns=NULL;
        if(curr!=NULL){
            recursionKaAns=reverseKGroup(curr,k);
            head->next=recursionKaAns;
        }

        return prev;


    }
};