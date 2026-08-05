/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();

        ListNode* curr = head;
        int k = lists.size();

        int check = 0;
        int idx = -1;
        int minVal = 1005;

        while (true)
        {
            for (int i = 0; i < k; i++)
            {
                if (lists[i] != NULL)
                {
                    if (lists[i]->val < minVal)
                    {
                        minVal = lists[i]->val;
                        idx = i;
                    }
                }
            }

            if (idx == -1)
            {
                break;
            }

            // cout << minVal << endl;
            curr->next = new ListNode(minVal);
            curr = curr->next;
            
            lists[idx] = lists[idx]->next;

            check = 0;
            idx = -1;
            minVal = 1005;
        }



        // curr = head->next;
        // while (curr != NULL)
        // {
        //     cout << curr->val << " ";
        //     curr = curr->next;
        // }

        return head->next;
    }
};
