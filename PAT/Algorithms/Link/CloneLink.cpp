#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode
{
    int label;
    struct ListNode *next, *random;
    ListNode(int x) :
        label(x), next(NULL), random(NULL)
    {
    }
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
        printf("%d ",head->label);
        head = head->next;
    }
    printf("\n");
}


ListNode* Clone(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return pHead;
    }
    ListNode* temp = pHead;
    while(temp != NULL)
    {
        ListNode* next = temp->next;
        ListNode* add = new ListNode(temp->label);
        temp->next = add;
        add->next = next;
        temp = temp->next->next;
    }

    temp = pHead;
    while(temp != NULL)
    {
        if(temp->random)
        {
            temp->next->random = temp->random->next;
        }
        else
        {
            temp->next->random = NULL;
        }
        temp = temp->next->next;
    }


    ListNode* newNode = new ListNode(0);
    newNode->next = pHead->next;
    ListNode* cur1 = pHead;
    ListNode* cur2 = pHead->next;
    while(cur1 && cur2)
    {
        if(cur1->next==NULL || cur1->next->next==NULL)
        {
            cur1->next = NULL;
        }
        else
        {
            cur1->next = cur1->next->next;
        }
        cur1 = cur1->next;

        if(cur2->next==NULL || cur2->next->next==NULL)
        {
            cur2->next = NULL;
        }
        else
        {
            cur2->next = cur2->next->next;
        }
        cur2 = cur2->next;
    }
    return newNode->next;
}

int main()
{
    ListNode* head = initLink();
    head = Clone(head);
    showLink(head);
}


