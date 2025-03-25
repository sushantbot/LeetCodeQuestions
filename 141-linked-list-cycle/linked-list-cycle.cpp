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
        ListNode*temp = head;
        unordered_map<ListNode*,bool>mapping;
        //Now we will store each and every Node which we tarverse
        while(temp!=NULL){
            //first Ask if already exists or not
            if(mapping.find(temp) != mapping.end()){
                //this if condition means temp node already exists
                return true;    // cycle present
            }

            //if Not then we will store it and proceed
            mapping[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};