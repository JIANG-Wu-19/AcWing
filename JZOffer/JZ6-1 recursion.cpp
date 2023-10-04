/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <cstddef>
class Solution {
public:
    void recursion(ListNode* head,vector<int>& res){
        if(head){
            recursion(head->next,res);
            res.push_back(head->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        recursion(head,res);
        return res;
    }
};
