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
        unordered_map<ListNode *,bool>mapping;
        ListNode *temp = head;
        while(temp != NULL){
            //sabse pehle check kr lunga ki ye node visited hai ya nahi
            //if this node is visited this means cycle present
            if(mapping.find(temp)!=mapping.end()){
                return true;
            }

            //Node not visited so store it
            mapping[temp]=true;
            temp=temp->next;
        }
        //when out of loop means there is NULL at end and no cycle present
        return false;
    }
};