#include <iostream>
#include <map>
using namespace std;

struct Node {
    char data;
    int count;
    Node *left, *right;
};

Node* createNode(char data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(Node* &root, char c)
{
    if (root == NULL) root = createNode(c);
    else if (root->data == c) root->count++;
    else if (root->data > c) insert(root->left, c);
    else insert(root->right, c);
}

void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << ": " << root->count << endl;
        inorder(root->right);
    }
}

int main()
{
    string s;
    Node *root = NULL;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        insert(root, s[i]);
    }
    inorder(root);
    return 0;
}
