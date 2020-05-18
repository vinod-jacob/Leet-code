#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* pairSwap(ListNode* first)
    {
        ListNode* second = first->next;
        first->next = second->next; //make first point to third
        second->next = first;
        return second;
    }

    ListNode* rev(ListNode* ptr, int k)
    {
        ListNode* ret = ptr; //intialize ret to ptr; so we can make use of it in the intial iteration within while loop. Then use ret keep track of ptr;
        while(k-1 > 0)
        {
            ptr = ret;
            ListNode* tmp = ptr;
            for (int i = 0; i < k-1; i++)
            {
                ptr = pairSwap(ptr);
                if (i == 0)
                    ret = ptr;
                else
                    tmp-> next = ptr;
                tmp = ptr;
                ptr = ptr->next;
            }
            k--;
        }
        return ret;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head) return head;

        ListNode *l = head, *ret = NULL;
        int len = 0;
        while (l)
        {
            len++;
            if(len == k) 
                ret = l;
            l = l->next;
        }
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        // curr->next = head;
        while(len/k > 0)
        {
            curr->next = rev(curr->next, k);
            for(int i = 0; i<k; i++) 
                curr = curr->next;
            len = len-k;
        }
        return ret;
    }
};

int main()
{
    ListNode N7 = ListNode(7);
    ListNode N6(6, &N7);
    ListNode N5 = ListNode(5, &N6); ListNode N4 = ListNode(4, &N5); ListNode N3 = ListNode(3, &N4); ListNode N2 = ListNode(2, &N3);  ListNode N1 = ListNode(1, &N2);

    ListNode* h = &N1;
    while (h != NULL)
    {
        cout << h->val;
        if (h->next != NULL) cout << "->";
        h = h->next;
    }
    cout << endl;
    Solution S1;

    h = &N1;
    h = S1.reverseKGroup(h, 6);

    while (h != NULL)
    {
        cout << h->val;
        if (h->next != NULL) cout << "->";
        h = h->next;
    }
    cout <<endl;
}