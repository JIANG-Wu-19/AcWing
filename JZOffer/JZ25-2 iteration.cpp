/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if(pHead1==NULL){
            return pHead2;
        }
        if(pHead2==NULL){
            return pHead1;
        }

        ListNode* res=new ListNode(0);
        ListNode* node=res;
        while(pHead1&&pHead2){
            if(pHead1->val<=pHead2->val){
                node->next=pHead1;
                pHead1=pHead1->next;
            }else{
                node->next=pHead2;
                pHead2=pHead2->next;
            }
            node=node->next;
        }
        if(pHead1){
            node->next=pHead1;
        }else{
            node->next=pHead2;
        }
        return res->next;
    }
};