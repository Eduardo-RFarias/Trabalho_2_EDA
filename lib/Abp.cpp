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
void Abp::remove(int value)
{
    this->root = remove_(this->root, value);
}
Abp::Node *Abp::remove_(Node *t, int x)
{
    Node *temp;
    if (t == NULL)
        return NULL;
    else if (x < t->value)
        t->left = remove_(t->left, x);
    else if (x > t->value)
        t->right = remove_(t->right, x);
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->value = temp->value;
        t->right = remove_(t->right, t->value);
    }
    else
    {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }
    if (t == NULL)
        return t;
    t = balance(t);
    return t;
}
//------------------------------------------------------------
void Abp::display()
{
    display_(this->root);
    cout << endl;
}
void Abp::display_(Node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display_(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Raiz -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "        ";
        cout << ptr->value;
        display_(ptr->left, level + 1);
    }
}
//------------------------------------------------------------
void Abp::showBalance()
{
    showBalance_(this->root);
}
void Abp::showBalance_(Node *root)
{
    if (root == NULL)
        return;
    showBalance_(root->left);
    cout << root->value << ":" << diff(root) << " | ";
    showBalance_(root->right);
}
//------------------------------------------------------------
//Helper functions
Abp::Node *Abp::balance(Node *temp)
{
    int bal_factor = diff(temp);
    temp->bal_factor = bal_factor;

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

Abp::Node *Abp::findMin(Node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

Abp::Node *Abp::findMax(Node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

int Abp::diff(Node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
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
