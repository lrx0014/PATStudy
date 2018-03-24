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

LinkNode* linkReverse(LinkNode* head)
{
    LinkNode* cur = head;
    LinkNode* pre = NULL;
    while(cur != NULL)
    {
        LinkNode* nxt = cur->next; //保存下一个节点的值
        cur->next = pre; //把当前cur的下一个节点指向Pre
        pre = cur; //此时Pre向后移动指向此时的cur
        cur = nxt; //而cur也向后移动，指向刚才保存的Nxt
    }
    return pre;
}

int main()
{
    LinkNode* head = initLink();
    showLink(head);
    printf("\n");
    head = linkReverse(head);
    showLink(head);
}
