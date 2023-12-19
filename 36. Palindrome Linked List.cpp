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


   ListNode* reverse(ListNode* head2){
       ListNode* curr = head2;
       ListNode* prev = NULL;
       ListNode* nex = head2->next;

       while(curr!=NULL && curr->next!=NULL){
           curr->next = prev;
           prev = curr;
           curr=nex;
           nex=curr->next;
       }

       curr->next = prev;

       return curr;
   }
  
    bool isPalindrome(ListNode* head) {

        //1)Find the length of LL
        //2) Iterate till half of the legth of LL
        //3)reverse from that half point
        //4)Compare both the lists
        //5) Return false if values differ else true


        ListNode* curr = head;
        int len = 0;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }

        int pos = len/2;
      
        curr = head;
        while(pos--){
            curr=curr->next;
        }

        ListNode* head2 = reverse(curr);

        while(head!=NULL && head2!=NULL){
            if(head->val != head2->val){
                return false;
            }

            head=head->next;
            head2=head2->next;
        }

        return true;
        
    }
};
