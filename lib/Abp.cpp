#include "Abp.hpp"

Abp::Abp()
{
    this->root = NULL;
}

Abp::~Abp()
{
    reset();
}

bool Abp::isEmpty()
{
    return this->root == NULL;
}

void Abp::free_(Node *node)
{
    if (node != NULL)
    {
        free_(node->right);
        free_(node->left);
        delete[] node;
    }
}

void Abp::reset()
{
    free_(this->root);
    this->root = NULL;
}
//------------------------------------------------------------
void Abp::insert(int value)
{
    this->root = insert_(value, this->root);
}
Abp::Node *Abp::insert_(int value, Node *root)
{
    if (root == NULL)
    {
        root = new Node;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->value)
    {
        root->left = insert_(value, root->left);
        root = balance(root);
    }
    else if (value >= root->value)
    {
        root->right = insert_(value, root->right);
        root = balance(root);
    }
    return root;
}
//------------------------------------------------------------
void Abp::displayTree()
{
    displayTree_(this->root);
    cout << endl;
}
void Abp::displayTree_(Node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        displayTree_(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Raiz -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "        ";
        cout << ptr->value;
        displayTree_(ptr->left, level + 1);
    }
}
//------------------------------------------------------------
void Abp::updateBalFactor()
{
    updateBalFactor_(this->root);
}
void Abp::updateBalFactor_(Node *root)
{
    if (root == NULL)
        return;

    root->bal_factor = diff(root);

    updateBalFactor_(root->left);
    cout << root->value << ":" << root->bal_factor << " | ";
    updateBalFactor_(root->right);
}
//------------------------------------------------------------
//Helper functions
Abp::Node *Abp::balance(Node *temp)
{

    int bal_factor = diff(temp);

    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = rotateLL(temp);
        else
            temp = rotateLR(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rotateRL(temp);
        else
            temp = rotateRR(temp);
    }
    return temp;
}

int Abp::height(Node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int Abp::diff(Node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    return l_height - r_height;
}

//Rotations
Abp::Node *Abp::rotateRR(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

Abp::Node *Abp::rotateLL(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

Abp::Node *Abp::rotateLR(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = rotateRR(temp);
    return rotateLL(parent);
}

Abp::Node *Abp::rotateRL(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = rotateLL(temp);
    return rotateRR(parent);
}
