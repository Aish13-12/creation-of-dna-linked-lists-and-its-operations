#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dataassi1.h"





int main()

{
	int l;
	struct node1*alpha=NULL;
	
	struct node1*beta=NULL;
	struct node1*alpha1=NULL;
	
	struct node1*beta1=NULL;
	struct node1*alpha2=NULL;
	
	struct node1*beta2=NULL;
	alpha=(struct node1*)malloc(sizeof(struct node1));
	
	beta=(struct node1*)malloc(sizeof(struct node1));
	alpha1=(struct node1*)malloc(sizeof(struct node1));
	
	beta1=(struct node1*)malloc(sizeof(struct node1));
	alpha2=(struct node1*)malloc(sizeof(struct node1));
	
	beta2=(struct node1*)malloc(sizeof(struct node1));
	
	
	//append(&alpha,&beta,'A');
	//append(&beta,&alpha,'G');
	//append(&alpha,&beta,'T');
	createmolecule(&alpha,&beta,4);
	insertdna(&alpha,&beta,'T',5);
	deletenucl(&alpha,&beta,3);
	splitmole(&alpha,&beta,&alpha1,&beta1,&alpha2,&beta2);
	
	
	
	
	
	l=len(beta);
	printf("%d\n",l);
	printmolecule(&alpha,&beta);
	printf("\n");
	
	//printchain1(&alpha);
   
    
   
    
    return 0;

}	
	



