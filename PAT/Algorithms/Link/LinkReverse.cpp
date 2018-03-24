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
        LinkNode* nxt = cur->next; //������һ���ڵ��ֵ
        cur->next = pre; //�ѵ�ǰcur����һ���ڵ�ָ��Pre
        pre = cur; //��ʱPre����ƶ�ָ���ʱ��cur
        cur = nxt; //��curҲ����ƶ���ָ��ղű����Nxt
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
