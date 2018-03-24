#include <stdio.h>

struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(int x):val(x),next(NULL){}
};

LinkNode* initLink()
{
    LinkNode* head;
    LinkNode* L1 = new LinkNode(1);
    LinkNode* L2 = new LinkNode(2);
    LinkNode* L3 = new LinkNode(3);
    LinkNode* L4 = new LinkNode(4);
    L1->next = L2;
    L2->next = L3;
    L3->next = L4;
    head = L1;
    return head;
}

void showLink(LinkNode* head)
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
}

LinkNode* Recorder(LinkNode* head)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    LinkNode* fast = head;
    LinkNode* slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    LinkNode* pre = fast;
    LinkNode* cur = fast->next;
    fast->next = NULL;
    while(cur != NULL)
    {
        LinkNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    cur = head;
    LinkNode* cur2 = pre;
    while(cur!=NULL && cur2!=NULL)
    {
        LinkNode* nxt1 = cur->next;
        LinkNode* nxt2 = cur2->next;
        cur2->next = cur->next;
        cur->next = cur2;
        cur = nxt1;
        cur2 = nxt2;
    }
    return head;
}

int main()
{
    LinkNode* head = initLink();
    head = Recorder(head);
    showLink(head);
}
