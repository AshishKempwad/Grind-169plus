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

   ListNode* merge(ListNode* l1, ListNode* l2){
       ListNode* dummy = new ListNode(-1);
       ListNode* marker = dummy;

       while(l1 && l2){
           if(l1->val < l2->val){
               marker->next = l1;
               l1=l1->next;
               marker = marker->next;
           }
           else{
               marker->next = l2;
               l2=l2->next;
               marker = marker->next;
           }
       }
       if(l1){
           marker->next = l1;
        }

        if(l2){
            marker->next = l2;
        }

        return dummy->next;

   }



    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        return merge(list1,list2);
        
    }
};
