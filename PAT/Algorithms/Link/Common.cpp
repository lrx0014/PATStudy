#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        vector<int> result;
        ListNode* a = headA;
        ListNode* b = headB;
        
        if(a==NULL || b==NULL)
        {
            return result;
        }
        
        while(a!=NULL && b!=NULL)
        {
            if(a->val > b->val)
            {
                b = b->next;
            }
            else if(a->val < b->val)
            {
                a = a->next;
            }
            else
            {
                result.push_back(a->val);
                a = a->next;
            }
        }
        return result;
    }
};