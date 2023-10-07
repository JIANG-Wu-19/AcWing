/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* l1=pHead1,* l2=pHead2;
		int len1=length(pHead1),len2=length(pHead2);
		while(len1!=len2){
			if(len1>len2){
				l1=l1->next;
				len1--;
			}else{
				l2=l2->next;
				len2--;
			}
		}
		while(l1!=l2){
			l1=l1->next;
			l2=l2->next;
		}
		return l1;
    }
	int length(ListNode* head){
		int length=0;
		ListNode* cur=head;
		while(cur){
			length++;
			cur=cur->next;
		}
		return length;
	}
};
