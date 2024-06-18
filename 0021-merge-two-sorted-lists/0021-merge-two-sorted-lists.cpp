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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mList=NULL;
        ListNode** tail=&mList;
        while(list1 && list2){
            if(list1->val < list2->val){
                *tail=list1;
                list1=list1->next;
            }
            else{
                *tail=list2;
                list2=list2->next;
            }
            tail = &((*tail)->next);
        }
        if(list1!=NULL){
            *tail=list1;
        }
        else{
            *tail=list2;
        }
        return mList;
    }
};