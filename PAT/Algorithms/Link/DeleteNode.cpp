#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        // write code here
        ListNode* visit = pHead;
        if(visit->val == delVal)
        {
            pHead = visit->next;
            visit->next = NULL;
            return pHead;
        }
        
        ListNode* pre;
        while(visit != NULL)
        {
            if(visit->val != delVal)
            {
                pre = visit;
                visit = visit->next;
            }else{
                pre->next = visit->next;
                visit->next = NULL;
                return pHead;
            }
        }
        return pHead;
    }
};