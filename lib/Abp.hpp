#ifndef ABP
#define ABP

#include <iostream>
using namespace std;

class Abp
{
private:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
        int bal_factor;
    };

    Node *root;

    Node *balance(Node *);
    int height(Node *);
    int diff(Node *);
    Node *findMin(Node *);
    Node *findMax(Node *);

    Node *rotateRR(Node *);
    Node *rotateRL(Node *);
    Node *rotateLR(Node *);
    Node *rotateLL(Node *);

    Node *insert_(int, Node *);
    Node *remove_(Node *, int);
    void display_(Node *, int = 1);
    void showBalance_(Node *);

public:
    Abp();
    ~Abp();

    void insert(int value);
    void remove(int value);
    void display();
    void showBalance();
};

#endif