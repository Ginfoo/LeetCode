#pragma once
#include <math.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};
class solution {
public:
	//官方参考代码
	ListNode * addTwoNumber(ListNode* l1, ListNode * l2) {
		ListNode preHead(0);
		ListNode *p = &preHead;
		int carry = 0;
		while (l1 || l2 || carry) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next;
	}
	//个人代码
	ListNode * addTwoNumbers_g(ListNode*l1, ListNode* l2) {
		ListNode* result = l1;
		ListNode* cur = result;
		ListNode* cur_pre= nullptr;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int carry = 0;
		while (p1 != nullptr&&p2 != nullptr) {
			int sum=p1->val + p2->val+carry;
			cur->val = sum % 10;
			carry = sum / 10;
			cur_pre = cur;
			cur = cur->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (p1 != nullptr&&carry==1) {
			while (p1 != nullptr&&carry == 1) {
				int sum = p1->val + carry;
				cur->val = sum % 10;
				carry = sum / 10;
				cur_pre = cur;
				cur = cur->next;
				p1 = p1->next;
			}
		}
		else if (p2 != nullptr) {
			cur_pre->next = p2;
			cur = p2;
			while (p2 != nullptr&&carry == 1) {
				int sum = p2->val + carry;
				cur->val = sum % 10;
				carry = sum / 10;
				cur_pre = cur;
				cur = cur->next;
				p2 = p2->next;
			}
		}
		if (carry == 1) {
			cur_pre->next = new ListNode(1);
		}
		return result;
	}

};