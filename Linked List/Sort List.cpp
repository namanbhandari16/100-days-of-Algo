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
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *p;
        vector<int>a;
        while(head!=NULL)
        {
            a.push_back(head->val);
            head=head->next;
        }
        sort(a.begin(),a.end());
        ListNode *temp=new ListNode(a[0]);
        temp->next=NULL;
        p=temp;
        head=p;
        for(int i=1;i<a.size();i++)
        {
            ListNode *temp=new ListNode(a[i]);
            temp->next=NULL;
            p->next=temp;
            p=p->next;
        }
        return head;
    }
};
