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
    int getDecimalValue(ListNode* head) {
        int res=0;
        //funda is iterate till end and for each l shi and bitwise or(insitu conve)
        while(head!=nullptr){
            res=(res<<1)|head->val;
            head=head->next;
        }
        return res;
        
    }
};