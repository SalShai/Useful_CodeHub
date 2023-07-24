#include"listfunc.h"
#include<stdio.h>
#include<stdlib.h>

List *initializelist (List *list)
{
	list=(List *)malloc(sizeof(List));
	list->head=list->tail=NULL;
	list->count=0;
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

List *insertAtBeg(List *list,int value)
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

List *insertAtEnd(List *list,int value)
{
	Node *newnode;
	newnode=getnode(value);
	if(list->count==0)
	{
		list->head=list->tail=newnode;
	}
	else
	{
		list->tail->ptr=newnode;
		list->tail=newnode;
	}
	list->count++;
	return list;
}

List *insertAfterElement(List *list,int element,int value)
{
	Node *newnode;
	newnode=getnode(value);
	Node *temp=list->head;
	while(temp!=NULL && temp->data!=element)
	{
		temp=temp->ptr;
	}
	if(temp!=NULL)
	{
		newnode->ptr=temp->ptr;
		temp->ptr=newnode;
	}
	list->count++;
	return list;
}

List *insertAfterPosition(List *list,int position,int value)
{
	if(position==0)
	{
		insertAtBeg(list,value);
	}
	else if(position==list->count)
	{
		insertAtEnd(list,value);
	}
	else
	{
		Node *newnode;
		newnode=getnode(value);
		Node *temp=list->head;
		while(temp!=NULL && list->count!=position)
		{
			temp=temp->ptr;
		}
		if(temp!=NULL)
		{
			newnode->ptr=temp->ptr;
			temp->ptr=newnode;
		}
		list->count++;
		return list;
	}
}

List *deleteFromBeg(List *list)
{
	Node *temp;
	temp=list->head;
	list->head=list->head->ptr;
	free(temp);
	list->count--;
	return list;
}

List *deleteFromEnd(List *list)
{
	Node *temp;
	temp=list->head;
	while(temp->ptr!=list->tail)
	{
		temp=temp->ptr;
	}
	list->tail=temp;
	temp=temp->ptr;	
	free(temp);
	list->tail->ptr=NULL;
	list->count--;
	return list;
}

List *deleteAfterElement(List *list,int element)
{
	Node *prev;
	Node *temp=list->head;
	while(temp!=NULL && temp->data!=element)
	{
		prev=temp;
		temp=temp->ptr;
	}
	prev->ptr=temp->ptr;
	free(temp);
	list->count--;
	return list;
}

List *deleteAfterPosition(List *list,int position)
{
	Node *prev=NULL;
	Node *temp=list->head;
	int c=0;
	while(temp!=NULL && c!=position)
	{
		prev=temp;
		temp=temp->ptr;
		c++;
	}
	prev->ptr=temp->ptr;
	free(temp);
	list->count--;
	return list;
}

int mini(List *list)
{
	Node *min=list->head;
	Node *temp=min->ptr;
	while(temp!=NULL)
	{
		if(min->data>temp->data)
		{
			min=temp;
		}
		temp=temp->ptr;
	}
return min->data;
}
int maxi(List *list)
{

	Node *maxi=list->head;
	Node *temp=maxi->ptr;
	while(temp!=NULL)
	{
		if(maxi->data <= temp->data)
		{
			maxi=temp;
		}
		temp=temp->ptr;
	}
return maxi->data;
}

void *searchEle(List *list,int value)
{
	Node *temp;
	temp=list->head;
		while(NULL!=temp && temp->data!=value)
		{	
				temp=temp->ptr;
		}
	
 if(temp!=NULL)
     printf("%d Found\n", value);
  else
	 printf("%d Not Found!!\n", value);;
}

void display(Node *list)
{
	while(list!=NULL)
	{
		printf("%d->",list->data);
		list=list->ptr;
	}
	printf("NULL");
}
