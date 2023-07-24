#include"listfunc.c"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int main()
{
List *list;

list=initializelist(list);
list=insertAtBeg(list,10);
list=insertAtBeg(list,20);
list=insertAtBeg(list,30);
list=insertAtBeg(list,40);
assert(list->count==4);
assert(list->head->data==40);
assert(list->tail->data==10);
list=insertAtEnd(list,60);
list=insertAtEnd(list,70);
list=insertAtEnd(list,100);
list=insertAtEnd(list,90);
assert(list->count==8);
assert(list->head->data==40);
assert(list->tail->data==90);
list=insertAfterElement(list,30,50);
list=insertAfterPosition(list,0,50);
assert(list->count==10);
list=deleteFromBeg(list);
list=deleteFromEnd(list);
assert(list->count==8);
list=deleteAfterElement(list,70);
list=deleteAfterPosition(list,4);
assert(list->count==6);
printf("Link List :\n");
display(list->head);

printf("\nMinimum: %d\n", mini(list));

printf("Maximum: %d\n", maxi(list));
searchEle(list,100);
searchEle(list,10);
return 0;
}

