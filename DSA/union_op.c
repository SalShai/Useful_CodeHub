#include"union.h"
#include<stdio.h>
#include<stdlib.h>

linkedlist *initializelist (linkedlist *list)
{
	list=(linkedlist *)malloc(sizeof(list));
	list->head=list->tail=NULL;
	list->count=0;
	return list;
}

linkedlist *insert(linkedlist *list,int value)
{
	Node *newnode;
	newnode=getnode(value);
	if(list->count==0)
	{
		list->head=list->tail=newnode;
	}
	else
	{
		newnode->ptr=list->head;
		list->head=newnode;
	}
	list->count++;
	return list;
}




Node *getnode(int value)
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(newnode));
	newnode->data=value;
	newnode->ptr=NULL;
	return newnode;
}

void displa(Node *list)
{
	while(list!=NULL)
	{
		printf("%d->",list->data);
		list=list->ptr;
	}
}
