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
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;
        head = nodeReverser(head);
        ListNode* h1 = head;
        h1 = h1->next;
        while(h1->next != NULL)
        {
            h1->next = nodeReverser(h1->next);
            if (h1->next->next != NULL) h1 = h1->next->next;
            else break;
        }
        return head;
    }

    ListNode* nodeReverser(ListNode* ptr)
    {
        if(!ptr || !ptr->next) return ptr;
        ListNode* temp = ptr->next;
        ptr->next = ptr->next->next;
        temp->next = ptr;
        return temp;
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
    h = S1.swapPairs(h);

    while (h != NULL)
    {
        cout << h->val;
        if (h->next != NULL) cout << "->";
        h = h->next;
    }
    cout <<endl;
}
