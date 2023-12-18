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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* marker = dummy;

        while(left && right){
            if(left->val < right->val){
                marker->next = left;
                left=left->next;
                marker = marker->next;
            }
            else{
                marker->next=right;
                right=right->next;
                marker=marker->next;
            }
        } 

        if(left){
            marker->next = left;
        }

        if(right){
            marker->next = right;
        }


        return dummy->next;
    }

    ListNode* mergesort(vector<ListNode*>& lists, int l, int h){
        if(l==h){
            return lists[l];
        }

        int mid = l + (h-l)/2;
        ListNode* left = mergesort(lists,l,mid);
        ListNode* right = mergesort(lists,mid+1,h);

        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        int n = lists.size();
        return mergesort(lists,0,n-1);
    }
};
