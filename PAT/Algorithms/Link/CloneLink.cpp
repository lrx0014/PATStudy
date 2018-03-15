#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* temp = pHead;
        while(temp != NULL)
        {
            RandomListNode* next = temp->next;
            RandomListNode* add = new RandomListNode(temp->label);
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
        
        RandomListNode* newNode = new RandomListNode(0);
        newNode = pHead->next;
        RandomListNode* res = pHead->next;
        while(newNode != NULL)
        {
            if(newNode->next != NULL && newNode->next->next != NULL)
            {
                newNode->next = newNode->next->next;
            }
            else
            {
                newNode->next = NULL;
            }
            newNode = newNode->next;
        }
        return res;
    }
};