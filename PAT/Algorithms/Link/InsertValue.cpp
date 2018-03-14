#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class InsertValue {
public:
    ListNode* insert(vector<int> A, int val) {
        // write code here
        ListNode* insert_node = new ListNode(val);
        if(A.size()==0)
        {
            insert_node->next = insert_node;
            return insert_node;
        }
         
        ListNode* head = new ListNode(A[0]);
        ListNode* cur = head;
        for(int i=1;i<A.size();i++)
        {
            ListNode* temp = new ListNode(A[i]);
            cur->next = temp;
            cur = temp;
        }
        cur->next = head;
         
        ListNode* visit = head;
        if(visit->val < insert_node->val)
        {
            ListNode* pre = visit;
            visit = visit->next;
            while(visit!=head)
            {
                if(visit->val < insert_node->val)
                {
                    pre = visit;
                    visit = visit->next;
                }else{
                    pre->next = insert_node;
                    insert_node->next = visit;
                    return head;
                }
            }
            pre->next = insert_node;
            insert_node->next = NULL;
            return head;
        }else{
            ListNode* pre = visit;
            visit = visit->next;
            while(visit!=head)
            {
                pre = visit;
                visit = visit->next;
            }
            pre->next = insert_node;
            insert_node->next = NULL;
        }
        return head;
    }
};