#include"union.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int main()
{



	list *A;
	A=Intialize(A);
	
	assert(A->head==NULL);
	
        Insert(A,7);
	Insert(A,5);
	Insert(A,1);
	Insert(A,1);
	Insert(A,2);
	Insert(A,6);
	sorting(A);
        display (A);



return 0;
}
