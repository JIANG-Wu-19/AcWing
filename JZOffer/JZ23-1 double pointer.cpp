
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        ListNode* l1=pHead,* l2=pHead;
        while(l1!=NULL&&l1->next!=NULL){
            l1=l1->next->next;
            l2=l2->next;
            if(l1==l2) break;
        }

        if(l1==NULL||l1->next==NULL) return NULL;
        l1=pHead;

        while(l1!=l2){
            l1=l1->next;
            l2=l2->next;
        }

        return l1;
    }
};