#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void catNode(ListNode* &head,ListNode* &pre,ListNode* &dest)
{
    if(head == NULL)
    {
        head = dest;
        pre = dest;
    }
    else
    {
        pre->next = dest;
        pre = pre->next;
    }
}

ListNode* listDivide(ListNode* head, int val)
{
    // write code here
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    ListNode* minHead = NULL;
    ListNode* maxHead = NULL;
    ListNode* minPre  = NULL;
    ListNode* maxPre  = NULL;
    ListNode* p       = head;

    while(p != NULL)
    {
        if(p->val <= val)
        {
            catNode(minHead,minPre,p);
        }
        else
        {
            catNode(maxHead,maxPre,p);
        }
        p = p->next;
    }

    ListNode* result   = NULL;
    ListNode* backNode = NULL;

    if(minHead != NULL)
    {
        result   = minHead;
        backNode = minPre;
    }

    if(maxHead != NULL)
    {
        if(result == NULL)
        {
            result   = maxHead;
            backNode = maxPre;
        }
        else
        {
            backNode->next = maxHead;
            backNode = maxPre;
        }
    }
    backNode->next = NULL;
    return result;
}

int main()
{
    ListNode *L1 = new ListNode(1);
    ListNode *L2 = new ListNode(4);
    ListNode *L3 = new ListNode(2);
    ListNode *L4 = new ListNode(5);

    L1->next = L2;
    L2->next = L3;
    L3->next = L4;

    ListNode* result = listDivide(L1,3);

    while(result != NULL)
    {
        printf("%d ",result->val);
        result = result->next;
    }
}
