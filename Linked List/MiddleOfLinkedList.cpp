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
    ListNode* middleNode(ListNode* head) {
        int length = findLength(head);
        int mid=0;
        int value;
        while(head && mid!= length/2)
        {
            mid++;
            value= head->val;
            head=head->next;
        }
        return head;
    }
    int findLength(ListNode * head)
    {
        int l=0;
        while(head)
        {
            l++;
            head = head->next;
        }
        return l;
    }
};
