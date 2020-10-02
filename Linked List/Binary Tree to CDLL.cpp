// C++ Program to convert a Binary Tree 
// to a Circular Doubly Linked List 
#include <bits/stdc++.h>
using namespace std;

// To represents a node of a Binary Tree 
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Create a new Node and return its address 
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *bTreeToCList(Node *root);

// Display Circular Link List
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data << " ";
        itr = itr->right;
    } while (head != itr);
    cout << endl;
    itr = itr->left;
    do
    {
        cout << itr->data << " ";
        itr = itr->left;
    } while (head != itr);
    cout << itr->data << endl;
}
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver Program to test above function
int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        Node *head = bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function converts a tree to a circular Linked List 
void convert(Node *root, Node **head)
{
    if (root == NULL)
        return;
    static Node *prev = NULL;
    convert(root->left, head);
    if (!(*head))
    {
        *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convert(root->right, head);
}
Node *bTreeToCList(Node *root)
{
    //add code here.
    Node *head = NULL;
    convert(root, &head);
    Node *p = head;
    while (p->right)
    {
        p = p->right;
    }
    p->right = head;
    head->left = p;
    return head;
}
