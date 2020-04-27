#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                ptr->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                ptr->val = l2->val;
                l2 = l2->next;
            }
            ptr->next = new ListNode(0);
            ptr = ptr->next;
        }

        while(l1 != NULL)
        {
            ptr->val = l1->val;
            if (l1->next != NULL)
            {
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }
            l1 = l1->next;
        }

        while(l2 != NULL)
        {
            ptr->val = l2->val;
            if(l2->next != NULL)
            {   
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }
            l2 = l2->next;
        }
        return head;
    }
};

int main()
{
    ListNode a1(0),a2(0),a3(0),a4(0);
    ListNode b1(0),b2(0),b3(0), b4(0);
    // ListNode* a1 = NULL;

    a1.next = &a2; a2.next = &a3; a3.next = &a4;
    b1.next = &b2; b2.next = &b3, b3.next = &b4;

    Solution s1;
    ListNode* head = s1.mergeTwoLists(&a1, &b1);

    while(head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
            cout << "->";
        head = head->next;
    }
    cout <<endl;
}