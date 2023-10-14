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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr) return head;
        if(head->val==val){
            ListNode* res=head->next;
            return res;
        }
        ListNode* l=head;
        while(l){
            if(l->next&&l->next->val==val){
                l->next=l->next->next;
                break;
            }
            l=l->next;
        } 
        return head;
    }
};
