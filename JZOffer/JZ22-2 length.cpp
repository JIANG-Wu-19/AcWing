/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    int len(ListNode* pHead){
        ListNode* l=pHead;
        int len=0;
        while(l){
            len++;
            l=l->next;
        }
        return len;
    }
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        int length=len(pHead);
        if(length<k || k==0) return NULL;
        int n=length-k;
        while(n--){
            pHead=pHead->next;
        }
        return pHead;
    }
};