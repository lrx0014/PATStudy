#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Insert(vector<int> A, vector<int> nxt, int val)
{
    if(A.empty() || nxt.empty())
    {
        return NULL;
    }
    ListNode* head = new ListNode(A[0]);
    ListNode* temp = head;
    for(int i=0;i<A.size()-1;i++)
    {
        ListNode* newNode = new ListNode(A[nxt[i]]);
        temp->next = newNode;
        temp = newNode;
    }
    ListNode* node_in = new ListNode(val);
    if(val < head->val)
    {
        temp->next = node_in;
        node_in->next = head;
        return node_in;
    }
    ListNode* pre = head;
    ListNode* cur = pre->next;
    while(cur != NULL)
    {
        if(pre->val <= val && val <= cur->val)
        {
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = node_in;
    node_in->next = cur;
    if(val < head->val)
    {
        return node_in;
    }
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

int main()
{
    int a[] = {1,3,4,5,7};
    int b[] = {1,2,3,4,0};
    vector<int> A(begin(a),end(a));
    vector<int> nxt(begin(b),end(b));
    ListNode* head = Insert(A,nxt,2);
    showLink(head);
}
