#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data to the left of the root: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of the tree: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << endl;
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << endl;
}

void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r2->left, r2->right);

    bool ans = r1->data == r2->data;

    if (left && right && ans)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    PreorderTraversal(root);

    levelOrderTraversal(root);

    return 0;
}