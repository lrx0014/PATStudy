#include <stdio.h>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* initLink()
{
    ListNode* head;
    ListNode* L1 = new ListNode(1);
    ListNode* L2 = new ListNode(2);
    ListNode* L3 = new ListNode(3);
    ListNode* L4 = new ListNode(4);
    ListNode* L5 = new ListNode(5);
    ListNode* L6 = new ListNode(6);
    ListNode* L7 = new ListNode(7);
    ListNode* L8 = new ListNode(8);
    L1->next = L2;
    L2->next = L3;
    L3->next = L4;
    L4->next = L5;
    L5->next = L6;
    L6->next = L7;
    L7->next = L8;
    head = L1;
    return head;
}

void showLink(ListNode* head)
{
    if(head == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}

void Reverse(ListNode* left,ListNode* start,ListNode* end,ListNode* right)
{
    ListNode* pre = start;
    ListNode* cur = pre->next;
    ListNode* nxt = NULL;
    while(cur != right)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    if(left != NULL)
    {
        left->next = end;
    }
    start->next = right;
}

ListNode* kReverse(ListNode* head,int k)
{
    if(k<2)
    {
        return head;
    }
    ListNode* cur = head;
    ListNode* pre = NULL;
    ListNode* start = NULL;
    ListNode* nxt = NULL;
    int cnt = 1;
    while(cur != NULL)
    {
        nxt = cur->next;
        if(cnt == k)
        {
            start = (pre==NULL?head:pre->next);
            head = (pre==NULL?cur:head);
            Reverse(pre,start,cur,nxt);
            pre = start;
            cnt = 0;
        }
        cnt++;
        cur = nxt;
    }
    return head;
}

int main()
{
    ListNode* head = initLink();
    showLink(head);
    head = kReverse(head,3);
    showLink(head);
}
