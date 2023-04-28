#include <iostream>

using namespace std;
struct Node
{
    int data;
    int index;
    Node *next;
};
Node* makeNode(int x, int index)
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->index = index;
    new_node->next = NULL;
    return new_node;
}
void addFront(Node *&head, int x, int index)
{
    Node* temp=makeNode(x, index);
    temp->next=head;
    head=temp;
}
void addBack(Node *&head, int x, int index)
{
    if(head==NULL)
        addFront(head, x, index);
    else
    {
        Node* last=makeNode(x, index);
        Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=last;
    }
}
Node *add(Node *mat1, Node *mat2)
{
    Node *mat3 = NULL;
    while(mat1 != NULL && mat2 != NULL)
    {
        if(mat1->index < mat2->index)
        {
            addBack(mat3, mat1->data, mat1->index);
            mat1 = mat1->next;
        }
        else if(mat1->index == mat2->index)
        {
            addBack(mat3, mat1->data + mat2->data, mat1->index);
            mat1 = mat1->next;
            mat2 = mat2->next;
        }
        else
        {
            addBack(mat3, mat2->data, mat2->index);
            mat2 = mat2->next;
        }
    }
    while(mat1 != NULL)
    {
        addBack(mat3, mat1->data, mat1->index);
        mat1 = mat1->next;
    }
    while(mat2 != NULL)
    {
        addBack(mat3, mat2->data, mat2->index);
        mat2 = mat2->next;
    }
    return mat3;
}
Node *subtract(Node *mat1, Node *mat2)
{
    Node *mat3 = NULL;
    while(mat1 != NULL && mat2 != NULL)
    {
        if(mat1->index < mat2->index)
        {
            addBack(mat3, mat1->data, mat1->index);
            mat1 = mat1->next;
        }
        else if(mat1->index == mat2->index)
        {
            addBack(mat3, mat1->data - mat2->data, mat1->index);
            mat1 = mat1->next;
            mat2 = mat2->next;
        }
        else
        {
            addBack(mat3, -(mat2->data), mat2->index);
            mat2 = mat2->next;
        }
    }
    while(mat1 != NULL)
    {
        addBack(mat3, mat1->data, mat1->index);
        mat1 = mat1->next;
    }
    while(mat2 != NULL)
    {
        addBack(mat3, -(mat2->data), mat2->index);
        mat2 = mat2->next;
    }
    return mat3;
}
void display(Node *mat, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(mat != NULL && ((mat->index / col) == i) && ((mat->index % col) == j))
            {
                cout << mat->data << " ";
                mat = mat->next;
            }
            else cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    int m, n;
    cout << "Nhap vao so hang, so cot cua hai ma tran: ";
    cin >> m >> n;
    Node *mat1 = NULL, *mat2 = NULL;
    cout << "Nhap cac phan tu cua ma tran thu nhat:" << endl;
    int x;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            if(x != 0)
            {
                addBack(mat1, x, i * n + j);
            }
        }
    }
    cout << "Nhap cac phan tu cua ma tran thu hai:" << endl;
    int y;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            if(x != 0)
            {
                addBack(mat2, x, i * n + j);
            }
        }
    }
    Node *mat3 = add(mat1, mat2);
    cout << "Tong hai ma tran:" << endl;
    display(mat3, m, n);
    Node *mat4 = subtract(mat1, mat2);
    cout << "Hieu hai ma tram:" << endl;
    display(mat4, m, n);
    return 0;
}
