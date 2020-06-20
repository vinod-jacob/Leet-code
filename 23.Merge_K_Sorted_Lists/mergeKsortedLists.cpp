#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode *ptr, *anchor;
        ptr = new ListNode(-1);
        anchor = ptr;

        while(1)
        {
            bool allEmpty = true;
            int smallest = INT32_MAX;
            int indextoadvance = 0;
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] != NULL)
                {
                    allEmpty = false;
                    if (lists[i]->val < smallest)
                    {
                        smallest = lists[i]->val;
                        indextoadvance = i;
                    }
                }
            }
            if(!allEmpty)
            {
                ptr->next = new ListNode(smallest);
                ptr = ptr -> next;
                lists[indextoadvance] = lists[indextoadvance]->next;
            }
            else
            {
                break;
            }
        }
        return anchor->next;
    }
};