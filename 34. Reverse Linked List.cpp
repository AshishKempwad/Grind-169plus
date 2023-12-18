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
    ListNode* reverseList(ListNode* head) {

        if(!head){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = curr->next;

        while(curr->next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nex;
            nex=curr->next;
        }
        curr->next=prev;

        return curr;
    }
};
