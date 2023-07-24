#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct _Node_{
    int reg, grade;
    char name[100];
    struct _Node_ *next;
}node;
 
struct _Hash_{
    node *head;
    int count;
};
typedef struct _Hash_ hash;



node *createNode(int reg, char *name, int grade);
void insertToHash(int reg, char *name, int grade);
void deleteFromHash(int reg,int grade);
void searchInHash(int reg,int grade);
void display();