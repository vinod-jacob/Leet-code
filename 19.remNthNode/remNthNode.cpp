#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* h1 = head;
        ListNode* h2 = head;
        
        while(n != 0 )
        {
            if (h1->next !=NULL) //this means remove the first element
                h1 = h1->next;
            else
            {
                head = head->next;
                return head;
            }
            n--;
        }
        while(h1->next != NULL)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        h2->next = h2->next->next;
        return head;
    }
};

int main()
{
    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    ListNode* head = &l1;
    l1.next = &l2; l2.next = &l3; l3.next = &l4; l4.next = &l5;

    cout << "----orginal seq---      " << endl;;
    for(ListNode* i = head; i != NULL; i = i->next)
    {
        cout << i->val;
        if (i->next != NULL) cout << "->"; 
    }
    cout << endl;
    Solution S1;
    ListNode* new_head = S1.removeNthFromEnd(head, 2);

    cout << "---- Altered seq---      " << endl;
    for(ListNode* i = new_head; i != NULL; i = i->next)
    {
        cout << i->val;
        if (i->next != NULL) cout << "->"; 
    }
    cout << endl;
}