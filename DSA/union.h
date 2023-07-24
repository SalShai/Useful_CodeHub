#include<stdint.h>

struct _node_
{
int data;
struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _Linklist_ 
{
Node *head,*tail;
int count;
};
typedef struct _Linklist_ linkedlist;

linkedlist *initializelist(linkedlist *);
linkedlist *insert_A(linkedlist *,int);

Node *getnode(int);
void display(Node *);
