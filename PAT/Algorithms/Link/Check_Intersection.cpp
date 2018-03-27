
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ChkIntersection {
public:
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
        // write code here
        if(hasRing(head1)==false && hasRing(head2)==false)
        {
            return chk_no_ring(head1,head2);
        }
        if(hasRing(head1)==false || hasRing(head2)==false)
        {
            return false;
        }
        return chk_has_ring(head1,head2);
    }

    bool hasRing(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != slow)
        {
            if(fast==NULL || fast->next==NULL)
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* findEntry(ListNode* head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;


        while(fast!=NULL && fast->next!=NULL)
        {
            if(fast==NULL || fast->next==NULL)
            {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

    bool chk_no_ring(ListNode* head1,ListNode* head2)
    {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while(p1->next != NULL)
        {
            p1 = p1->next;
        }
        while(p2->next != NULL)
        {
            p2 = p2->next;
        }
        if(p1 == p2)
        {
            return true;
        }
        return false;
    }

    bool chk_has_ring(ListNode* head1,ListNode* head2)
    {
        if(head1==NULL || head2==NULL)
        {
            return false;
        }
        ListNode* p1 = findEntry(head1);
        ListNode* p2 = findEntry(head2);
        if(p1 == p2)
        {
            return true;
        }
        ListNode* cur = p1;
        cur = cur->next;
        while(cur != p1)
        {
            if(cur == p2)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};
