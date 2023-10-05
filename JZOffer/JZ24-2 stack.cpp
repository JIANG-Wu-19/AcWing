/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstddef>
#include <stack>
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

        stack<ListNode*> s;
        while(head){
            s.push(head);
            head=head->next;
        }

        ListNode* node=s.top();
        ListNode* reverse=node;
        s.pop();

        while(!s.empty()){
            ListNode* tmp=s.top();
            s.pop();
            node->next=tmp;
            node=node->next;
        }
        node->next=NULL;
        return reverse;
    }
};