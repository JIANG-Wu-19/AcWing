
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
#include <unordered_set>
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        unordered_set<ListNode*> set;
        while(pHead){
            if(set.find(pHead)!=set.end()){
                return pHead;
            }
            set.insert(pHead);
            pHead=pHead->next;
        }
        return NULL;
    }
};