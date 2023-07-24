#include<stdio.h>
#include "setunion.h"
#include <assert.h>


int main()
{
	List *A,*B;
	List *C;

	A=initialList(A);
	B=initialList(B);
	
	

	A=insert_at_begin(A,1);
 	A=insert_at_begin(A,2);
	A=insert_at_begin(A,3);
	A=insert_at_begin(A,4);
	A=insert_at_begin(A,5);
	display(A);

	B=insert_at_begin(B,1);
	B=insert_at_begin(B,2);
	B=insert_at_begin(B,5);
	B=insert_at_begin(B,8);
	display(B);

	C=merge(A,B);
	display(C);
	printf("sorted data");

        C=sortasen(C);
	display(C);
	

return 0 ;
}

