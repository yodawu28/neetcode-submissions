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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* merged;

        if (curr1 == NULL)
        {
            return curr2;
        }

        if (curr2 == NULL)
        {
            return curr1;
        }

        if (curr1->val <= curr2->val)
        {
            merged = new ListNode(curr1->val);
            curr1 = curr1->next;
        }
        else
        {
            merged = new ListNode(curr2->val);
            curr2 = curr2->next;
        }

        ListNode* ans = merged;


        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->val <= curr2->val)
            {
                merged->next = new ListNode(curr1->val);
                curr1 = curr1->next;
            }
            else
            {
                merged->next = new ListNode(curr2->val);
                curr2 = curr2->next;
            }
            merged = merged->next;
        }

        if (curr1 != NULL)
        {
            merged->next = curr1;
        }

        if (curr2 != NULL)
        {
            merged->next = curr2;
        }

        return ans;
    }
};
