#include <stdio.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int main()
{
    int T, i, n1, n2, n3, l, k;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        struct Node *head1 = NULL, *tail1 = NULL;
        for (i = 1; i <= n1; i++)
        {
            cin >> l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL, *tail2 = NULL;
        for (i = 1; i <= n2; i++)
        {
            cin >> l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL, *tail3 = NULL;
        for (i = 1; i <= n3; i++)
        {
            cin >> l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
            tail1->next = head3;
        if (tail2 != NULL)
            tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int intersectPoint(Node *head1, Node *head2)
{
    Node *p1 = head1, *p2 = head2;
    int c = 0, d = 0, diff;
    while (p1 != NULL)
    {
        c++;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        d++;
        p2 = p2->next;
    }
    int k = max(c, d);
    p1 = head1;
    p2 = head2;
    if (k == c)
    {
        diff = c - d;
        for (int i = 0; i < diff; i++)
        {
            if (p1 == NULL)
            {
                return -1;
            }
            p1 = p1->next;
        }
    }
    else
    {
        diff = d - c;
        for (int i = 0; i < diff; i++)
        {
            if (p2 == NULL)
            {
                return -1;
            }
            p2 = p2->next;
        }
    }
    while (p1 && p2)
    {
        if (p1 == p2)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}
