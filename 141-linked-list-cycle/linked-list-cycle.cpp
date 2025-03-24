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

            //otherwise continue traversing and pushing true
            mapping[temp]=true;

            temp=temp->next;
        }
        return false;
    }
};