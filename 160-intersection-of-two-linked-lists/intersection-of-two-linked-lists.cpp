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
        ListNode *tempA=headA;
        ListNode *tempB=headB;

        //traverse tbtk krenge jbtk dono null nhi hai
        //jaise koi ek null ho jayega loop se baahr ho jayenge
        while(tempA->next!=NULL && tempB->next!=NULL){
            if(tempA==tempB){
                return tempA;
                //return tempB;
            }
            //agar aisa nhi hai to next krte jayenge
            tempA=tempA->next;
            tempB=tempB->next;
        }
        //yahan pe hain iska mtlbb koi ek null ho chuka hai 
        if(tempA->next==NULL){
            // agar tempA null hua hai to tempB kitna bara hai tempA se ye check krenge
            int Blen=0;
            while(tempB->next!=nullptr){
                tempB=tempB->next;
                Blen++;
            }
            //Ab jab tk blen 0 na ho jaaye tbtk head B ko mve krwayenge
            while(Blen!=0){
                Blen--;
                headB=headB->next;
            }
        }
        else{
            // agar tempA null hua hai to tempB kitna bara hai tempA se ye check krenge
            int Alen=0;
            while(tempA->next!=nullptr){
                tempA=tempA->next;
                Alen++;
            }
            //Ab jab tk blen 0 na ho jaaye tbtk head B ko mve krwayenge
            while(Alen!=0){
                Alen--;
                headA=headA->next;
            }
        }

        //Ab dono pointer ko tbtk move krwaynege jab tk match na kr jaaye
        //jab match kr jayega to usko hi return kr denge
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
        
        
    }
};


//Solved By Sushant  again on 14th-june-2024