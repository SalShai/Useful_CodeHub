#include "hash.h"

hash *hashTable = NULL;
int eleCount=0;

node *createNode(int reg, char *name, int grade) 
{
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    newnode->reg = reg;
    newnode->grade = grade;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}
 
void insertToHash(int reg, char *name, int grade) {
    int hashIndex = grade % eleCount;
    node *newnode = createNode(reg, name, grade);

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
 
void deleteFromHash(int reg,int grade) {
    
    int hashIndex = grade % eleCount, flag = 0;
    node *temp, *myNode;
   
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Given data is not present in hash Table!!\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        
        if (myNode->reg == reg) {
            flag = 1;
            if (myNode == hashTable[hashIndex].head)
                hashTable[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;
 
            hashTable[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag)
        printf("Data deleted successfully from Hash Table\n");
    else
        printf("Given data is not present in hash Table!!!!\n");
    return;
}
 
void searchInHash(int reg,int grade) {
    int hashIndex = grade % eleCount, flag = 0;
    node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->reg == reg) {
            printf("register Number: %d\n", myNode->reg);
            printf("Name     : %s\n", myNode->name);
            printf("grade      : %d\n", myNode->grade);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}
 
void display() {
    node *myNode;
    int i;
    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("register     Name          grade   \n");
        printf("--------------------------------\n");
        while (myNode != NULL) {
            printf("%-12d", myNode->reg);
            printf("%-15s", myNode->name);
            printf("%d\n", myNode->grade);
            myNode = myNode->next;
        }
    }
    return;
}