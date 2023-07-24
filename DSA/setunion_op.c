#include "setunion.h"
#include<stdlib.h>
#include<stdio.h>

List * initialList(List *list)
{
	
	list = (List*)malloc(sizeof(List));        
        list->head=list->tail=NULL;
	list->len=0;
	return list;
}  

List * insert_at_begin(List *list,int data)
{
	Node *newNode;
	newNode = getNode(data);

	if(NULL == list->head)
	{
		list->head = list->tail = newNode;


	}

	else 

	{
		newNode->ptr = list->head;
		list->head = newNode;


	}

list->len++;
return list;
}

Node * getNode(int data)
{
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->ptr = NULL;
	return newNode;
}



List * merge(List *A,List *B)
{
	Node *temp_a,*temp_b;
	List *C;
	temp_a = A->head;
	temp_b = B->head;
	C=initialList(C);
	while(temp_a!=NULL)
	{
		C=insert_at_begin(C,temp_a->data);
		temp_a=temp_a->ptr;
	}
	
	while(temp_b!=NULL)
	{
		C=insert_at_begin(C,temp_b->data);
		temp_b=temp_b->ptr;


	}
return C;
}
List * sortasen(List *C)
{
	Node *temp,*prev;
	int ele;
	for(temp=C->head;temp->ptr!=NULL;temp=temp->ptr)
		{
			for(prev=temp->ptr;prev!=NULL;prev=prev->ptr)
			{
				if(temp->data < prev->data)
				{
					ele=temp->data;
					temp->data=prev->data;
					prev->data=ele;
				}
			}
		}
   return C;
}

void display(List *mylist)

{

	Node *temp;
	temp=mylist->head;
	printf("Elements are\n");
	while(NULL!=temp)
	{
		printf("%d\n",temp->data);
		temp=temp->ptr;
	}
}


