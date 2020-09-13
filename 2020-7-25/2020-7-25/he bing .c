
#include <stdio.h>
#include <windows.h>
 Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	if (l1 == NULL || l2 == NULL)
		return NULL;
	struct ListNode* p = l1;
	//struct ListNode* p1=p->next;
	struct ListNode* q = l2;
	struct ListNode* q1 = q->next;
	struct ListNode* tmp = NULL;
	q->next = NULL;
	while (q != NULL)
	{
		if (q->val == p->val || q->val>p->val)
		{
			q->next = p->next;
			p->next = q;

		}
		else
		{
			if (tmp == NULL)
			{
				q->next = l1;
				l1 = q;
			}
			else{

				q->next = tmp->next;
				tmp->next = q;

			}
			q = q1;
			q1 = q1->next;
			tmp = p;
			p = p->next;


		}

	}
	
	return p;

}
int main()
{
	system("pause");
	return 0;
}