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
typedef struct _Linklist_ List;

Node *getnode(int);
List *initializelist(List *);
List *insertAtBeg(List *,int);
List *insertAtEnd(List *,int);
List *insertAfterElement(List *,int,int);
List *insertAtPosition(List *,int,int);
List *deleteFromBeg(List *);
List *deleteFromEnd(List *);
List *deleteAfterElement(List *,int);
List *deleteAfterPosition(List *,int);
void *searchEle(List *,int);
void display(Node *);
int mini(List *);
int maxi(List *);