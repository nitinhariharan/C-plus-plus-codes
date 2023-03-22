#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Node* newNode(int value)
{
    Node* n = new Node;
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* insertValue(struct Node* root, int value,
                        queue<Node *>& q)
{
    Node* node = newNode(value);
    if (root == NULL)
        root = node;

    else if (q.front()->left == NULL)
        q.front()->left = node;

    else {
        q.front()->right = node;
        q.pop();
    }

    q.push(node);
    return root;
}

Node* createTree(int arr[], int n)
{
    Node* root = NULL;
    queue<Node*> q;
    for (int i = 0; i < n; i++)
    root = insertValue(root, arr[i], q);
    return root;
}

void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> n;
    n.push(root);
    while (!n.empty()) {
        cout << n.front()->data << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}

int ans(Node * root,int &res)
{
    if(root==NULL) return 0;
    int l =ans(root->left,res);
    int r=ans(root->right,res);

    int temp=max(max(l,r)+root->data,root->data);

    int temp1=max(temp,l+r+root->data);

    res=max(res,temp1);
    return res;
}

int main()
{
    int arr[] = { 10, 8, 2 ,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);
    //levelOrder(root);
    int res=INT_MIN;
    cout<<ans(root,res);
    return 0;
}
