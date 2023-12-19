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
    ListNode* rotateRight(ListNode* head, int k) {

        //Story:
        //1)Calculate the length of the LL (len)
        //2)Connect the last node to first. i.e lastnode->next=first (circular LL)
        //3) Calculate (pos) to move.
            // pos = (len - k)%len    //We mod by len, becuase sometimes k could be greater than len and that could cuase us to rotate unnesseserily.
        //4)Then move by pos
        //5)The head = curr_node->next and make curr_node->next=NULL
  
         if(head==NULL){
             return NULL;
         }
       
        int len = 1;
        ListNode* tail = head;    

        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }

        tail->next = head; ///Created circular LL
        int pos = len - k%len;

        while(pos--){
            tail=tail->next;
        }

        head = tail->next;

        tail->next= NULL;

       return head;
    }
};
