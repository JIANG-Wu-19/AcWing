/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstddef>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* reverse=ReverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return reverse;
    }
};