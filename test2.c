#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dataassi1.h"

int main()
{
	struct node1*j;
	struct node1*h;
	struct node1*k;
	
	
	
	j=createmolecule1();
	h=j->down;
	
	insertdna(&j,&h,'A',2);
	printmolecule(&j,&h);
	deletenucl(&j,&h,3);
	printmolecule(&j,&h);
	
	k=splitmole(&j,&h,1);
	printmolecule(&k,&k->down);
	insertdna(&j,&h,'A',1);
	printmolecule(&j,&h);
	return 0;
}	
	
	

	//splitmole(&j,&h,1);
	
	//len(&j);
	

