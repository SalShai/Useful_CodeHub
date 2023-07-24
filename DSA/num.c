#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct hash *hashTable = NULL;
 
struct node{
    int num;
    struct node *next;
};
 
struct hash{
    struct node *head;
    int count;
};

 
struct node *createNode(int value) 
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->num=value;
    newnode->next = NULL;
    return newnode;
}
int hashKey(int value)
{
    if(value%2==0)
        return 1;
    else
        return 0;
}

 void insertToHash(int value)
{
    int hashIndex = hashKey(value);
    struct node *newnode = createNode(value);
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    
    newnode->next = (hashTable[hashIndex].head);
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}
void display() {
    struct node *myNode;
    int i;
    //print even
    printf("even:");
        myNode = hashTable[0].head;
        while (myNode != NULL) 
        {
            printf("%d\t", myNode->num);
            myNode = myNode->next;
        }
    //print odd
    printf("\nOdd:");
        myNode = hashTable[1].head;
        while (myNode != NULL) 
        {
            printf("%d\t", myNode->num);
            myNode = myNode->next;
        }
    return;
}
int main()
{
    int n,i;
    printf("Enter the number:");
    scanf("%d", &n);
    /* create hash table with "n" no of buckets */
    hashTable = (struct hash *) calloc(2, sizeof(struct hash));
    for (int i = 0; i <=n; i++)
    {
        insertToHash(i);
    }
display();
return 0;
}
